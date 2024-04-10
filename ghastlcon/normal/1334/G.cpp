#include <bits/stdc++.h>
#define N 524289
#define uint unsigned int
#define uint64 unsigned long long

constexpr uint Max_size = 1 << 21 | 5;
constexpr uint g = 3, Mod = 998244353;

inline uint norm_2(const uint x)
{
    return x < Mod * 2 ? x : x - Mod * 2;
}

inline uint norm(const uint x)
{
    return x < Mod ? x : x - Mod;
}

struct Z
{
    uint v;
    Z() { }
    Z(const uint _v) : v(_v) { }
};

inline Z operator+(const Z x1, const Z x2) { return norm(x1.v + x2.v); }
inline Z operator-(const Z x1, const Z x2) { return norm(x1.v + Mod - x2.v); }
inline Z operator-(const Z x) { return x.v ? Mod - x.v : 0; }
inline Z operator*(const Z x1, const Z x2) { return static_cast<uint64>(x1.v) * x2.v % Mod; }
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }

Z Power(Z Base, int Exp)
{
    Z res = 1;
    for (; Exp; Base *= Base, Exp >>= 1)
        if (Exp & 1)
            res *= Base;
    return res;
}

inline uint mf(uint x)
{
    return (static_cast<uint64>(x) << 32) / Mod;
}

int size;
uint w[Max_size], w_q[Max_size];

inline uint mult_Shoup_2(const uint x, const uint y, const uint y_q)
{
    uint q = static_cast<uint64>(x) * y_q >> 32;
    return x * y - q * Mod;
}

inline uint mult_Shoup(const uint x, const uint y, const uint y_q)
{
    return norm(mult_Shoup_2(x, y, y_q));
}

inline uint mult_Shoup_q(const uint x, const uint y, const uint y_q)
{
    uint q = static_cast<uint64>(x) * y_q >> 32;
    return q + (x * y - q * Mod >= Mod);
}

inline void init(int n)
{
    for (size = 2; size < n; size <<= 1)
        ;
    uint pr = Power(g, (Mod - 1) / size).v;
    uint pr_q = (static_cast<uint64>(pr) << 32) / Mod;
    uint pr_r = (static_cast<uint64>(pr) << 32) % Mod;
    size >>= 1;
    w[size] = 1, w_q[size] = (static_cast<uint64>(w[size]) << 32) / Mod;
//  for (int i = 1; i != size; ++i)
//      w[size + i] = mult_Shoup(w[size + i - 1], pr, pr_q), w_q[size + i] = (static_cast<uint64>(w[size + i]) << 32) / Mod;
#define compute(r, r_q, b, b_q)\
    do\
    {\
        uint x = b;\
        uint64 p = static_cast<uint64>(x) * pr_q;\
        uint q = p >> 32;\
        r = norm(x * pr - q * Mod);\
        r_q = static_cast<uint>(p) + mult_Shoup_q(pr_r, b, b_q);\
    } while (0)
    if (size <= 4)
    {
        for (int i = 1; i != size; ++i)
            compute(w[size + i], w_q[size + i], w[size + i - 1], w_q[size + i - 1]);
    }
    else
    {
        for (int i = 1; i != 8; ++i)
            compute(w[size + i], w_q[size + i], w[size + i - 1], w_q[size + i - 1]);
        pr = w[size + 4], pr_q = w_q[size + 4], pr_r = -pr_q * Mod;
        for (int i = 8; i != size; i += 4)
        {
            compute(w[size + i + 0], w_q[size + i + 0], w[size + i - 4], w_q[size + i - 4]);
            compute(w[size + i + 1], w_q[size + i + 1], w[size + i - 3], w_q[size + i - 3]);
            compute(w[size + i + 2], w_q[size + i + 2], w[size + i - 2], w_q[size + i - 2]);
            compute(w[size + i + 3], w_q[size + i + 3], w[size + i - 1], w_q[size + i - 1]);
        } 
    }
    for (int i = size - 1; i; --i)
        w[i] = w[i * 2], w_q[i] = w_q[i * 2];
    size <<= 1;
}

inline void DFT_fr_2(Z _A[], const int L)
{
    if (L == 1)
        return;
    uint *A = reinterpret_cast<uint *>(_A);
//  auto butterfly1 = [](uint &a, uint &b)
//  {
//      uint x = norm_2(a + b), y = norm_2(a + Mod * 2 - b);
//      a = x, b = y;
//  };
#define butterfly1(a, b)\
    do\
    {\
        uint _a = a, _b = b;\
        uint x = norm_2(_a + _b), y = norm_2(_a + Mod * 2 - _b);\
        a = x, b = y;\
    } while (0)
    if (L == 2)
    {
        butterfly1(A[0], A[1]);
        return;
    }
//  auto butterfly = [](uint &a, uint &b, const uint _w, const uint _w_q)
//  {
//      uint x = norm_2(a + b), y = mult_Shoup_2(a + Mod * 2 - b, _w, _w_q);
//      a = x, b = y;
//  };
#define butterfly(a, b, _w, _w_q)\
    do\
    {\
        uint _a = a, _b = b;\
        uint x = norm_2(_a + _b), y = mult_Shoup_2(_a + Mod * 2 - _b, _w, _w_q);\
        a = x, b = y;\
    } while (0)
    if (L == 4)
    {
        butterfly1(A[0], A[2]);
        butterfly(A[1], A[3], w[3], w_q[3]);
        butterfly1(A[0], A[1]);
        butterfly1(A[2], A[3]);
        return; 
    }
    for (int d = L >> 1; d != 4; d >>= 1)
        for (int i = 0; i != L; i += d << 1)
            for (int j = 0; j != d; j += 4)
            {
                butterfly(A[i + j + 0], A[i + d + j + 0], w[d + j + 0], w_q[d + j + 0]);
                butterfly(A[i + j + 1], A[i + d + j + 1], w[d + j + 1], w_q[d + j + 1]);
                butterfly(A[i + j + 2], A[i + d + j + 2], w[d + j + 2], w_q[d + j + 2]);
                butterfly(A[i + j + 3], A[i + d + j + 3], w[d + j + 3], w_q[d + j + 3]);
            }
    for (int i = 0; i != L; i += 8)
    {
        butterfly1(A[i + 0], A[i + 4]);
        butterfly(A[i + 1], A[i + 5], w[5], w_q[5]);
        butterfly(A[i + 2], A[i + 6], w[6], w_q[6]);
        butterfly(A[i + 3], A[i + 7], w[7], w_q[7]);
    }
    for (int i = 0; i != L; i += 8)
    {
        butterfly1(A[i + 0], A[i + 2]);
        butterfly(A[i + 1], A[i + 3], w[3], w_q[3]);
        butterfly1(A[i + 4], A[i + 6]);
        butterfly(A[i + 5], A[i + 7], w[3], w_q[3]);
    }
    for (int i = 0; i != L; i += 8)
    {
        butterfly1(A[i + 0], A[i + 1]);
        butterfly1(A[i + 2], A[i + 3]);
        butterfly1(A[i + 4], A[i + 5]);
        butterfly1(A[i + 6], A[i + 7]);
    }
#undef butterfly1
#undef butterfly
}

inline void IDFT_fr(Z _A[], const int L)
{
    if (L == 1)
        return;
    uint *A = reinterpret_cast<uint *>(_A);
//  auto butterfly1 = [](uint &a, uint &b)
//  {
//      uint x = norm_2(a), t = norm_2(b);
//      a = x + t, b = x + Mod * 2 - t;
//  };
#define butterfly1(a, b)\
    do\
    {\
        uint _a = a, _b = b;\
        uint x = norm_2(_a), t = norm_2(_b);\
        a = x + t, b = x + Mod * 2 - t;\
    } while (0)
    if (L == 2)
    {
        butterfly1(A[0], A[1]);
        A[0] = norm(norm_2(A[0])), A[0] = A[0] & 1 ? A[0] + Mod : A[0], A[0] /= 2;
        A[1] = norm(norm_2(A[1])), A[1] = A[1] & 1 ? A[1] + Mod : A[1], A[1] /= 2;
        return;
    }
//  auto butterfly = [](uint &a, uint &b, const uint _w, const uint _w_q)
//  {
//      uint x = norm_2(a), t = mult_Shoup_2(b, _w, _w_q);
//      a = x + t, b = x + Mod * 2 - t;
//  };
#define butterfly(a, b, _w, _w_q)\
    do\
    {\
        uint _a = a, _b = b;\
        uint x = norm_2(_a), t = mult_Shoup_2(_b, _w, _w_q);\
        a = x + t, b = x + Mod * 2 - t;\
    } while (0)
    if (L == 4)
    {
        butterfly1(A[0], A[1]);
        butterfly1(A[2], A[3]);
        butterfly1(A[0], A[2]);
        butterfly(A[1], A[3], w[3], w_q[3]);
        std::swap(A[1], A[3]);
        for (int i = 0; i != L; ++i)
        {
            uint64 m = -A[i] & 3;
            A[i] = norm((A[i] + m * Mod) >> 2);
        }
        return; 
    }
    for (int i = 0; i != L; i += 8)
    {
        butterfly1(A[i + 0], A[i + 1]);
        butterfly1(A[i + 2], A[i + 3]);
        butterfly1(A[i + 4], A[i + 5]);
        butterfly1(A[i + 6], A[i + 7]);
    }
    for (int i = 0; i != L; i += 8)
    {
        butterfly1(A[i + 0], A[i + 2]);
        butterfly(A[i + 1], A[i + 3], w[3], w_q[3]);
        butterfly1(A[i + 4], A[i + 6]);
        butterfly(A[i + 5], A[i + 7], w[3], w_q[3]);
    }
    for (int i = 0; i != L; i += 8)
    {
        butterfly1(A[i + 0], A[i + 4]);
        butterfly(A[i + 1], A[i + 5], w[5], w_q[5]);
        butterfly(A[i + 2], A[i + 6], w[6], w_q[6]);
        butterfly(A[i + 3], A[i + 7], w[7], w_q[7]);
    }
    for (int d = 8; d != L; d <<= 1)
        for (int i = 0; i != L; i += d << 1)
            for (int j = 0; j != d; j += 4)
            {
                butterfly(A[i + j + 0], A[i + d + j + 0], w[d + j + 0], w_q[d + j + 0]);
                butterfly(A[i + j + 1], A[i + d + j + 1], w[d + j + 1], w_q[d + j + 1]);
                butterfly(A[i + j + 2], A[i + d + j + 2], w[d + j + 2], w_q[d + j + 2]);
                butterfly(A[i + j + 3], A[i + d + j + 3], w[d + j + 3], w_q[d + j + 3]);
            }
#undef butterfly1
#undef butterfly
    std::reverse(A + 1, A + L);
    int k = __builtin_ctz(L);
    for (int i = 0; i != L; ++i)
    {
        uint64 m = -A[i] & (L - 1);
        A[i] = norm((A[i] + m * Mod) >> k);
    }
}

int p[N];
char a[N], b[N];
int o[N];
Z f[N], ff[N];

int main(void)
{
    int m, n;
    int i, t, c;

    for(i = 0; i < 26; i ++)
    {
        scanf("%d", &p[i]);
        p[i] --;
    }
    scanf("%s %s", a, b);
    m = (int)strlen(a);
    n = (int)strlen(b);
    for(c = 0; (1 << c) < n + m; c ++)
        ;

    init(1 << c);

    for(t = 0; t < 26; t ++)
    {
        for(i = 0; i < (1 << c); i ++)
            f[i] = Z(0);
        for(i = 0; i < m; i ++)
            f[m - i - 1] = Z(a[i] == (t + 'a'));
        for(i = 0; i < n; i ++)
            ff[i] = Z(b[i] == (t + 'a') || b[i] == (p[t] + 'a'));

        DFT_fr_2(f, 1 << c);
        DFT_fr_2(ff, 1 << c);
        for(i = 0; i < (1 << c); i ++)
            f[i] *= ff[i];
        IDFT_fr(f, 1 << c);

        for(i = 0; i < n; i ++)
            o[i] += f[m - 1 + i].v;
    }

    for(i = 0; i < n - m + 1; i ++)
        putchar((o[i] == m) + 48);

    return 0;
}