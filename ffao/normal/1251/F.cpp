#pragma GCC target("avx2")
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <immintrin.h>
#include <cassert>
    
namespace IO {
    const int BUFFER_SIZE = 1 << 15;
    
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
    
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    
    char number_buffer[100];
    uint8_t lookup[100];
    
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
    
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
    
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
    
        return input_buffer[advance ? input_pos++ : input_pos];
    }
    
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
    
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
    
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
    
        if (negative)
            number = -number;
    }
    
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
    
    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }
    
    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();
    
        output_buffer[output_pos++] = c;
    }
    
    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }
    
        int length = 0;
    
        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }
    
        if (number != 0 || length == 0)
            write_char(number + '0');
    
        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);
    
        if (after)
            write_char(after);
    }
    
    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
    
        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


typedef unsigned char U8;
typedef int I32;
typedef unsigned int U32;
typedef long long I64;
typedef unsigned long long U64;
const int P=998244353;
const int inv2=(P+1)>>1;
const int G=3;
const int GInv=332748118;
const int MaxExp=22;
const int MAXN=1048576<<1;
const int MAXK=500005;
const int BmM=288737297;
const int BmW=29;
namespace NTT{

    U32 GcdEx(U32 A, U32 B, I32& x, I32& y) {
        if (!B) {
            x = 1;
            y = 0;
            return A;
        }
        U32 d = GcdEx(B, A % B, y, x);
        y -= x * (I32) (A / B);
        return d;
    }

    inline U32 MNorm(I32 V) {
        V = V % P;
        return (U32) (V < 0 ? V + P : V);
    }

    inline U32 MAdd(U32 A, U32 B) {
        U32 res = A + B;
        return res < P ? res : res - P;
    }

    inline U32 MSub(U32 A, U32 B) {
        U32 res = A - B;
        return A < B ? res + P : res;
    }

    inline U32 MMul(U32 A, U32 B) {
        return (U32) ((U64) A * B % P);
    }

    inline U32 MPow(U32 A, U32 B) {
        U32 res = 1;
        while (B) {
            if (B & 1)
                res = MMul(res, A);
            A = MMul(A, A);
            B >>= 1;
        }
        return res;
    }

    inline U32 MInv(U32 N) {
        I32 x, y;
        GcdEx(N, P, x, y);
        x %= P;
        return (U32) (x < 0 ? x + P : x);
    }

    inline __m256i VLod(const U32* __restrict__ A) {
        return _mm256_loadu_si256((const __m256i*) A);
    }

    inline void VSto(U32* __restrict__ A, __m256i v) {
        _mm256_storeu_si256((__m256i*) A, v);
    }

    inline __m256i VEx0(__m256i v) {
        const __m256i vm0 = _mm256_set_epi64x(
            0x111111111b1a1918, 0x1111111113121110,
            0x111111110b0a0908, 0x1111111103020100
        );
        return _mm256_shuffle_epi8(v, vm0);
    }

    inline __m256i VEx1(__m256i v) {
        const __m256i vm1 = _mm256_set_epi64x(
            0x111111111f1e1d1c, 0x1111111117161514,
            0x111111110f0e0d0c, 0x1111111107060504
        );
        return _mm256_shuffle_epi8(v, vm1);
    }

    inline __m256i VIntlv(__m256i v0, __m256i v1) {
        return _mm256_blend_epi32(v0, _mm256_shuffle_epi32(v1, 0xb1), 0xaa);
    }

    inline __m256i VAdd(__m256i va, __m256i vb) {
        const __m256i vm32 = _mm256_set1_epi32(P);
        __m256i vra = _mm256_add_epi32(va, vb);
        __m256i vrb = _mm256_sub_epi32(vra, vm32);
        return _mm256_min_epu32(vra, vrb);
    }

    inline __m256i VSub(__m256i va, __m256i vb) {
        const __m256i vm32 = _mm256_set1_epi32(P);
        __m256i vra = _mm256_sub_epi32(va, vb);
        __m256i vrb = _mm256_add_epi32(vra, vm32);
        return _mm256_min_epu32(vra, vrb);
    }

    inline __m256i VMul(__m256i va0, __m256i va1, __m256i vb0, __m256i vb1) {
        const __m256i vm32 = _mm256_set1_epi32(P);
        const __m256i vm64 = _mm256_set1_epi64x(P);
        const __m256i vbmm = _mm256_set1_epi64x(BmM);
        __m256i vmul0 = _mm256_mul_epi32(va0, vb0);
        __m256i vmul1 = _mm256_mul_epi32(va1, vb1);
        __m256i vlow = VIntlv(vmul0, vmul1);
        __m256i vquo0 = _mm256_srli_epi64(_mm256_mul_epi32(_mm256_srli_epi64(vmul0, 29), vbmm), BmW);
        __m256i vquo1 = _mm256_srli_epi64(_mm256_mul_epi32(_mm256_srli_epi64(vmul1, 29), vbmm), BmW);
        __m256i vval0 = _mm256_mul_epi32(vquo0, vm64);
        __m256i vval1 = _mm256_mul_epi32(vquo1, vm64);
        __m256i vval = VIntlv(vval0, vval1);
        __m256i vra = _mm256_sub_epi32(vlow, vval);
        __m256i vrb = _mm256_add_epi32(vra, vm32);
        __m256i vrc = _mm256_sub_epi32(vra, vm32);
        __m256i vmin = _mm256_min_epu32(vra, vrb);
        return _mm256_min_epu32(vmin, vrc);
    }

    inline __m256i VMul(__m256i va, __m256i vb0, __m256i vb1) {
        return VMul(VEx0(va), VEx1(va), vb0, vb1);
    }

    inline __m256i VMul(__m256i va, __m256i vb) {
        return VMul(va, VEx0(vb), VEx1(vb));
    }

    inline void VMul(U32* __restrict__ A, U32 Len, U32 W) {
        if (Len < 8) {
            for (U32 i = 0; i < Len; ++i)
                A[i] = MMul(A[i], W);
            return;
        }
        __m256i vw = _mm256_set1_epi64x(W);
        for (U32 i = 0; i < Len; i += 8)
            VSto(A + i, VMul(VLod(A + i), vw, vw));
    }

    inline void VMul(U32* __restrict__ A, const U32* __restrict__ B, U32 Len) {
        if (Len < 8) {
            for (U32 i = 0; i < Len; ++i)
                A[i] = MMul(A[i], B[i]);
            return;
        }
        for (U32 i = 0; i < Len; i += 8)
            VSto(A + i, VMul(VLod(A + i), VLod(B + i)));
    }

    inline void VSqr(U32* __restrict__ A, U32 Len) {
        if (Len < 8) {
            for (U32 i = 0; i < Len; ++i)
                A[i] = MMul(A[i], A[i]);
            return;
        }
        for (U32 i = 0; i < Len; i += 8) {
            __m256i va = VLod(A + i);
            __m256i v0 = VEx0(va);
            __m256i v1 = VEx1(va);
            VSto(A + i, VMul(v0, v1, v0, v1));
        }
    }

    U32 WbFwd[MaxExp + 1];
    U32 WbInv[MaxExp + 1];
    U32 LenInv[MaxExp + 1];

    inline void NttInitAll(int Max) {
        for (int Exp = 0; Exp <= Max; ++Exp) {
            WbFwd[Exp] = MPow(G, (P - 1) >> Exp);
            WbInv[Exp] = MPow(GInv, (P - 1) >> Exp);
            LenInv[Exp] = MInv(1u << Exp);
        }
    }

    inline void NttImpl1(U32* __restrict__ A, U32 Len) {
        for (U32 j = 0; j < Len; j += 2) {
            U32 a0 = MAdd(A[j + 0], A[j + 1]);
            U32 b0 = MSub(A[j + 0], A[j + 1]);
            A[j + 0] = a0;
            A[j + 1] = b0;
        }
    }

    inline void NttFwd2(U32* __restrict__ A, U32 Len, U32 Wn) {
        for (U32 j = 0; j < Len; j += 4) {
            U32 a0 = MAdd(A[j + 0], A[j + 2]);
            U32 a1 = MAdd(A[j + 1], A[j + 3]);
            U32 b0 = MSub(A[j + 0], A[j + 2]);
            U32 b1 = MSub(A[j + 1], A[j + 3]);
            A[j + 0] = a0;
            A[j + 1] = a1;
            A[j + 2] = b0;
            A[j + 3] = MMul(b1, Wn);
        }
    }

    inline void NttFwd3(U32* __restrict__ A, U32 Len, U32 Wn) {
        U32 W2 = MMul(Wn, Wn);
        U32 W3 = MMul(W2, Wn);
        const __m128i vm32 = _mm_set1_epi32(P);
        for (U32 j = 0; j < Len; j += 8) {
            __m128i va = _mm_load_si128((const __m128i*) (A + j));
            __m128i vb = _mm_load_si128((const __m128i*) (A + j + 4));
            __m128i vc = _mm_add_epi32(va, vb);
            __m128i vd = _mm_sub_epi32(va, vb);
            __m128i ve = _mm_sub_epi32(vc, _mm_andnot_si128(_mm_cmpgt_epi32(vm32, vc), vm32));
            __m128i vf = _mm_add_epi32(vd, _mm_and_si128(_mm_cmpgt_epi32(vb, va), vm32));
            _mm_store_si128((__m128i*) (A + j), ve);
            _mm_store_si128((__m128i*) (A + j + 4), vf);
            A[j + 5] = MMul(Wn, A[j + 5]);
            A[j + 6] = MMul(W2, A[j + 6]);
            A[j + 7] = MMul(W3, A[j + 7]);
        }
    }
    inline void NttFwd(U32* __restrict__ A, int Exp) {
        U32 Len = 1u << Exp;
        U32 Wn = WbFwd[Exp];
        for (int i = Exp - 1; i >= 3; --i) {
            U32 ChkSiz = 1u << i;
            U32 tw2 = MMul(Wn, Wn);
            U32 tw3 = MMul(tw2, Wn);
            U32 tw4 = MMul(tw3, Wn);
            U32 tw5 = MMul(tw4, Wn);
            U32 tw6 = MMul(tw5, Wn);
            U32 tw7 = MMul(tw6, Wn);
            U32 twn = MMul(tw7, Wn);
            __m256i vw32 = _mm256_set_epi32(tw7, tw6, tw5, tw4, tw3, tw2, Wn, 1);
            __m256i vwn = _mm256_set1_epi64x(twn);
            for (U32 j = 0; j < Len; j += 2u << i) {
                U32* A_ = A + j;
                U32* B_ = A_ + ChkSiz;
                __m256i vw = vw32;
                for (U32 k = 0; k < ChkSiz; k += 8) {
                    __m256i va = VLod(A_ + k);
                    __m256i vb = VLod(B_ + k);
                    __m256i vw0 = VEx0(vw);
                    __m256i vw1 = VEx1(vw);
                    __m256i vc = VAdd(va, vb);
                    __m256i vd = VSub(va, vb);
                    VSto(A_ + k, vc);
                    VSto(B_ + k, VMul(vd, vw0, vw1));
                    vw = VMul(vw0, vw1, vwn, vwn);
                }
            }
            Wn = MMul(Wn, Wn);
        }
        if (Exp >= 3) {
            NttFwd3(A, Len, Wn);
            Wn = MMul(Wn, Wn);
        }
        if (Exp >= 2)
            NttFwd2(A, Len, Wn);
        if (Exp)
            NttImpl1(A, Len);
    }

    inline void NttInv2(U32* __restrict__ A, U32 Len, U32 Wn) {
        for (U32 j = 0; j < Len; j += 4) {
            U32 a0 = A[j + 0];
            U32 a1 = A[j + 1];
            U32 b0 = A[j + 2];
            U32 b1 = MMul(A[j + 3], Wn);
            A[j + 0] = MAdd(a0, b0);
            A[j + 1] = MAdd(a1, b1);
            A[j + 2] = MSub(a0, b0);
            A[j + 3] = MSub(a1, b1);
        }
    }

    inline void NttInv3(U32* __restrict__ A, U32 Len, U32 Wn) {
        U32 W2 = MMul(Wn, Wn);
        U32 W3 = MMul(W2, Wn);
        const __m128i vm32 = _mm_set1_epi32(P);
        for (U32 j = 0; j < Len; j += 8) {
            A[j + 5] = MMul(Wn, A[j + 5]);
            A[j + 6] = MMul(W2, A[j + 6]);
            A[j + 7] = MMul(W3, A[j + 7]);
            __m128i va = _mm_load_si128((const __m128i*) (A + j));
            __m128i vb = _mm_load_si128((const __m128i*) (A + j + 4));
            __m128i vc = _mm_add_epi32(va, vb);
            __m128i vd = _mm_sub_epi32(va, vb);
            __m128i ve = _mm_sub_epi32(vc, _mm_andnot_si128(_mm_cmpgt_epi32(vm32, vc), vm32));
            __m128i vf = _mm_add_epi32(vd, _mm_and_si128(_mm_cmpgt_epi32(vb, va),vm32));
            _mm_store_si128((__m128i*) (A + j), ve);
            _mm_store_si128((__m128i*) (A + j + 4), vf);
        }
    }

    inline void NttInv(U32* __restrict__ A, int Exp) {
        if (!Exp)
            return;
        U32 Len = 1u << Exp;
        NttImpl1(A, Len);
        if (Exp == 1) {
            VMul(A, Len, LenInv[1]);
            return;
        }
        U32 Ws[MaxExp];
        Ws[0] = WbInv[Exp];
        for (int i = 1; i < Exp; ++i)
            Ws[i] = MMul(Ws[i - 1], Ws[i - 1]);
        NttInv2(A, Len, Ws[Exp - 2]);
        if (Exp == 2) {
            VMul(A, Len, LenInv[2]);
            return;
        }
        NttInv3(A, Len, Ws[Exp - 3]);
        if (Exp == 3) {
            VMul(A, Len, LenInv[3]);
            return;
        }
        for (int i = 3; i < Exp; ++i) {
            U32 ChkSiz = 1u << i;
            U32 Wn = Ws[Exp - 1 - i];
            U32 tw2 = MMul(Wn, Wn);
            U32 tw3 = MMul(tw2, Wn);
            U32 tw4 = MMul(tw3, Wn);
            U32 tw5 = MMul(tw4, Wn);
            U32 tw6 = MMul(tw5, Wn);
            U32 tw7 = MMul(tw6, Wn);
            U32 twn = MMul(tw7, Wn);
            __m256i vw32 = _mm256_set_epi32(tw7, tw6, tw5, tw4, tw3, tw2, Wn, 1);
            __m256i vwn = _mm256_set1_epi64x(twn);
            for (U32 j = 0; j < Len; j += 2u << i) {
                U32* A_ = A + j;
                U32* B_ = A_ + ChkSiz;
                __m256i vw = vw32;
                for (U32 k = 0; k < ChkSiz; k += 8) {
                    __m256i vw0 = VEx0(vw);
                    __m256i vw1 = VEx1(vw);
                    __m256i vb = VMul(VLod(B_ + k), vw0, vw1);
                    vw = VMul(vw0, vw1, vwn, vwn);
                    __m256i va = VLod(A_ + k);
                    __m256i vc = VAdd(va, vb);
                    __m256i vd = VSub(va, vb);
                    VSto(A_ + k, vc);
                    VSto(B_ + k, vd);
                }
            }
        }
        VMul(A, Len, LenInv[Exp]);
    }

    inline int Log2Ceil(U32 N) {
        static const U8 Table[32] = {
            0,  9,  1,  10, 13, 21, 2,  29,
            11, 14, 16, 18, 22, 25, 3,  30,
            8,  12, 20, 28, 15, 17, 24, 7,
            19, 27, 23, 6,  26, 5,  4,  31,
        };
        N = (N << 1) - 1;
        N |= N >> 1;
        N |= N >> 2;
        N |= N >> 4;
        N |= N >> 8;
        N |= N >> 16;
        return (int) Table[(N * 0x07c4acddu) >> 27];
    }
}
    
template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);
    
    
struct FFT_mod {
    int mod, root, root_1, root_pw;
};
    
extern FFT_mod suggested_fft_mods[5];
    
    
void ntt(std::vector<int>& a, bool invert, const FFT_mod& mod_data);
    
    
using namespace std;
    
    
int n, k;
vector<int> ans;
vector<int> queries;
map<int,int> white;
vector<int> red;
    
vector<int> one = {1, 2};
vector<int> two = {1, 2, 1};
vector<int> onepot(524288);
vector<int> twopot(524288);
vector<int> poly(524288);

const FFT_mod mod = suggested_fft_mods[3];

const int sss = 28;
const int ttt = 33;
const long long qqq = (1LL<<(sss+ttt))/mod.mod;
    
int modpow(int b, int e) {
    int r = 1;
    while (e) {
        if (e&1) r = (r * 1ll * b) % mod.mod;
        b = (b * 1ll * b) % mod.mod; 
        e >>= 1;
    }
    return r;
}
    
inline __m256i mul_mod(const __m256i& x, const __m256i& y) {
    __m256i ql = _mm256_set1_epi64x(qqq);
    __m256i p = _mm256_set1_epi32(mod.mod); 
    __m256i al = _mm256_mul_epu32(x,y);
    __m256i bl = _mm256_srli_epi64(al, sss);
    __m256i cl = _mm256_srli_epi64(_mm256_mul_epu32(bl,ql), ttt);
    __m256i xh = _mm256_srli_si256(x,4);
    __m256i yh = _mm256_srli_si256(y,4);
    __m256i ah = _mm256_mul_epu32(xh,yh);
    __m256i bh = _mm256_srli_epi64(ah, sss);
    __m256i ch = _mm256_srli_epi64(_mm256_mul_epu32(bh,ql), ttt);
    __m256i a = _mm256_blend_epi16(al, _mm256_slli_si256(ah, 4), 4+8+64+128);
    __m256i c = _mm256_or_si256(cl, _mm256_slli_si256(ch, 4));
    __m256i d = _mm256_sub_epi32(a, _mm256_mullo_epi32(c,p));
    return _mm256_min_epu32(d, _mm256_sub_epi32(d,p));
}
    
void solve_red(int red) {
    int o = 0, t = 0;
    for (auto it : white) {
        if (it.first >= red) continue;
        if (it.second == 1) o++;
        else t++;
    }
    
    __m256i p = _mm256_set1_epi32(mod.mod);
    
    for (int i = 0; i < 524288; i+=8) {
        __m256i onev = _mm256_loadu_si256((__m256i*) &one[i]);
        onev = _mm256_min_epu32(onev, _mm256_sub_epi32(onev,p));
        __m256i onepotv = _mm256_set1_epi32(1);
        int to = o;
        while (to) {
            if (to & 1) onepotv = mul_mod(onepotv, onev);
            
            onev = mul_mod(onev, onev);
            to >>= 1;
        }
    
        __m256i twov = _mm256_loadu_si256((__m256i*) &two[i]);
        twov = _mm256_min_epu32(twov, _mm256_sub_epi32(twov,p));
        __m256i twopotv = _mm256_set1_epi32(1);
    
        to = t;
        while (to) {
            if (to & 1) twopotv = mul_mod(twopotv, twov);
            twov = mul_mod(twov, twov);
    
            to >>= 1;
        }
    
        __m256i polyv = mul_mod(onepotv, twopotv);
        _mm256_storeu_si256( (__m256i*) &poly[i], polyv);
    }
    
    NTT::NttInv((U32*) &poly[0], 19);
    //ntt(poly, true, mod);
    
    for (int i = 0; i < queries.size(); i++) {
        int rem = queries[i] - red - 1;
        if (rem >= 0 && rem < 524288) {
            ans[i] = (ans[i] + poly[rem]) % mod.mod;
        }
    }
}
    
void solve()
{
    one.resize(524288);
    two.resize(524288);
    NTT::NttFwd((U32*) &one[0], 19);
    NTT::NttFwd((U32*) &two[0], 19);
    //ntt(one, false, mod);
    //ntt(two, false, mod);
    
    IO::read_int(n, k);
    
    int w; 
    for (int i = 0; i < n; i++) {
        IO::read_int(w);
        white[w]++;
        if (white[w] >= 2) white[w] = 2;
    }
    
    red.resize(k);
    for (int i = 0; i < k; i++) IO::read_int(red[i]);
    
    int q;
    IO::read_int(q);
    ans.resize(q);
    queries.resize(q);
    for (int i = 0; i < q; i++) {
        IO::read_int(queries[i]);
        queries[i] /= 2;
    }
    
    for (int r : red) solve_red(r);
    
    for (int a : ans) IO::write_int(a,'\n');
}
    
    
#include <fstream>
    
    
int main() {
    IO::init();
    NTT::NttInitAll(19);
    solve();
}
    
    
template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}
    
template <typename T>
T modInv(T a, T m) {
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}
    
    
FFT_mod suggested_fft_mods[] = {
    { 7340033, 5, 4404020, 1 << 20 },
    { 415236097, 73362476, 247718523, 1<<22 },
    { 463470593, 428228038, 182429, 1<<21},
    { 998244353, 15311432, 469870224, 1 << 23 },
    { 918552577, 86995699, 324602258, 1 << 22 }
};
    
int FFT_w[1050000];
int FFT_w_dash[1050000];
    
    
void ntt(std::vector<int>& a, bool invert, const FFT_mod& mod_data) {
    int n = (int)a.size();
    int mod = mod_data.mod;
    
    for (int i = 1, j = 0; i<n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }
    
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? mod_data.root_1 : mod_data.root;
        for (int i = len; i<mod_data.root_pw; i <<= 1)
            wlen = int(wlen * 1ll * wlen % mod_data.mod);
        long long tt = wlen;
        for (int i = 1; i < len / 2; i++) {
            FFT_w[i] = tt;
            FFT_w_dash[i] = (tt << 31) / mod;
            int q = (FFT_w_dash[1] * 1ll * tt) >> 31;
            tt = (wlen * 1ll * tt - q * 1ll * mod) & ((1LL << 31) - 1);
            if (tt >= mod) tt -= mod;
        }
        for (int i = 0; i<n; i += len) {
            int uu = a[i], vv = a[i + len / 2] % mod;
            if (uu >= mod) uu -= mod;
            a[i] = uu + vv < mod ? uu + vv : uu + vv - mod;
            a[i + len / 2] = uu - vv >= 0 ? uu - vv : uu - vv + mod;
    
            for (int j = 1; j<len / 2; ++j) {
                int u = a[i + j];
                if (u >= mod) u -= mod;
                int q = (FFT_w_dash[j] * 1ll * a[i + j + len / 2]) >> 31;
                int v = (FFT_w[j] * 1ll * a[i + j + len / 2] - q * 1ll * mod) & ((1LL<<31)-1);
                if (v >= mod) v -= mod;
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v + mod;
            }
        }
    }
    if (invert) {
        int nrev = modInv(n, mod);
        for (int i = 0; i<n; ++i)
            a[i] = int(a[i] * 1ll * nrev % mod);
    }
}