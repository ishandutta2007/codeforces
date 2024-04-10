#include <cstdio>
typedef long long LL;

const LL mod = (LL)1e9 + 7;

inline LL getInt()
{
    unsigned char c = 0;
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    LL mul = 1;
    if (c == '-') mul = -1, c = getchar();
    LL num = 0;
    while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
    return num*mul;
}

struct matrix
{
    LL a[2][2];

    inline void init()
    {
        a[0][0] = 0; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = 0;
    }

    inline void nullMat()
    {
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 1; a[1][1] = 0;
    }

    inline void revNull()
    {
        a[0][0] = 0; a[0][1] = 2;
        a[1][0] = 1; a[1][1] = -1;
    }

    inline void doInit()
    {
        a[0][0] = 1; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = 1;
    }
};

LL t[2][2];

void mulOn(matrix& a, const matrix& b)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            t[i][j] = a.a[i][0] * b.a[0][j] + a.a[i][1] * b.a[1][j];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a.a[i][j] = t[i][j] % mod;
}

matrix res;

void binPow(matrix& a, LL n)
{
    res.doInit();
	while (n)
    {
		if (n & 1) mulOn(res, a);
		mulOn(a, a);
		n >>= 1;
	}
	a = res;
}

LL binPow(LL a, LL n)
{
	LL res = 1;
	while (n)
    {
		if (n & 1) res *= a, res %= mod;
		a *= a, a %= mod;
		n >>= 1;
	}
	return res;
}

LL q; matrix m;

void addMoves(LL cnt)
{
    q = binPow(q, cnt);
    binPow(m, cnt);
}

LL div2(LL a)
{
    while (a % 2 != 0) a += mod;
    return a / 2;
}

void rev()
{
    matrix w; w.revNull();
    mulOn(m, w);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m.a[i][j] = div2(m.a[i][j]);
    q = div2(q);
}

main()
{
    q = 2; m.nullMat();
    int k = getInt();
    for (int i = 0; i < k; i++)
    {
        LL n = getInt();
        addMoves(n);
    }
    rev(); rev();
    q = (q * 2) % mod;
    printf("%d/%d\n", int(m.a[0][0] % mod), int(q % mod));
    return 0;
}