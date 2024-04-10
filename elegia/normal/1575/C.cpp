#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const int MAXN = 200005;
const db PI = acos(-1);
const ll MOD = 1000000007;

struct Complex
{
	db real,imag;
	Complex (db R = 0,db I = 0)
	{
		real = R;
		imag = I;
	}
	Complex operator + (const Complex &p)const
	{
		return Complex(real + p.real,imag + p.imag);
	}
	Complex operator - (const Complex &p)const
	{
		return Complex(real - p.real,imag - p.imag);
	}
	Complex operator * (const Complex &p)const
	{
		return Complex(real * p.real - imag * p.imag,real * p.imag + imag * p.real);
	}
}a[MAXN << 2],b[MAXN << 2],wn[2][MAXN << 2];

int n,m,k,N;
int c[MAXN];
int d[MAXN];
int cnt2[MAXN];
int cnt3[MAXN];
int rev[MAXN << 2];

ll ans;
ll cnt[MAXN];

void FFTinit(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (N >> 1);
	int half = N >> 1;
	for (int i = 0;i < half;i++)
	{
		wn[0][half + i] = Complex(cos(PI * i / half),sin(PI * i / half));
		wn[1][half + i] = Complex(cos(PI * i / half),-sin(PI * i / half));
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}

void FFT(Complex *v,int inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += (i << 1))
		{
			Complex *l = v + j,*r = v + j + i,*w = wn[inv == -1] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *w * *r;
				*r = *l - A;
				*l = *l + A;
			}
		}
	if (inv == -1)
	{
		Complex Inv(1.0 / N,0);
		for (int i = 0;i < N;i++)
			v[i] = v[i] * Inv;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&c[i]);
		d[i] = (d[i - 1] + c[i]) % k;
	}
	int tot = (ll)d[n] * m % k;
	for (int i = 1;i <= n;i++)
		a[d[i]].real++;
	for (int i = 1;i < m;i++)
		b[(ll)i * d[n] % k].real++;
	FFTinit(k << 1 | 1);
	FFT(a,1);
	FFT(b,1);
	for (int i = 0;i < N;i++)
		a[i] = a[i] * b[i];
	FFT(a,-1);
	for (int i = 0;i <= k * 2;i++)
		cnt[i % k] += (ll)(a[i].real + 0.5);
	for (int i = 0;i < k;i++)
		cnt[i] %= MOD;
	for (int i = 1;i <= n;i++)
		cnt2[d[i]]++;
	for (int i = 1;i <= n;i++)
	{
		(ans += cnt2[d[i - 1]] + cnt[d[i - 1]] + cnt3[(d[i - 1] - tot + k) % k]) %= MOD;
		cnt2[d[i]]--;
		if (i > 1)
			cnt3[d[i - 1]]++;
	}
	(ans *= m) %= MOD;
	if (!tot)
		(ans -= m - 1) %= MOD;
	printf("%lld\n",ans);
	return 0;
}