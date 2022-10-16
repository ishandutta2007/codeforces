#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>
#include <immintrin.h>

using namespace std;

void re(int& x);

void pr(int x);

void pr(const char *x);

void ps();

typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <cstring>

int p[30];
char s[210000];
char t[210000];

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

const int xx = 524288; 

void solve()
{
	NTT::NttInitAll(19);
    rep(i,0,26) re(p[i]);

    scanf("%s", s);
    scanf("%s", t);

    int sn = strlen(s);
    int tn = strlen(t);

    rep(i,0,sn) s[i]-='a';
    rep(i,0,tn) t[i]-='a';

    // int xx = 1;
    // for (; xx < 2*(sn+tn); xx<<=1);

    vi o(xx,0);

    rep(i,0,26) {
        vi ss(xx,0);
        vi tt(xx,0);
        for (int j = 0; j < sn; j++) {
            ss[sn-j-1] = (s[j]==i) || (p[s[j]] == i+1);
        } 
        for (int j = 0; j < tn; j++) {
            tt[j] = (t[j] == i);
        }

		NTT::NttFwd((U32*) &tt[0], 19);
		NTT::NttFwd((U32*) &ss[0], 19);

		rep(i,0,xx) o[i] = (o[i]+ss[i]*1ll*tt[i])%P;
    }

	NTT::NttInv((U32*) &o[0], 19);
    rep(i,0,tn-sn+1) pr((int)(o[i+(sn-1)] == sn));
    ps();
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }