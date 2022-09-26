#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const double PI = 3.1415926536;

int n,x,la,lb,N;
int a[MAXN];
int rev[MAXN << 2];

ll ans[MAXN];

struct Complex
{
	double real,imag;
	Complex(double a = 0,double b = 0)
	{
		real = a;
		imag = b;
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
		return Complex(real * p.real - imag * p.imag,real * p.imag + p.real * imag);
	}
	Complex operator / (const double &p)const
	{
		return Complex(real / p,imag / p);
	}
}pa[MAXN << 2],pb[MAXN << 2];

void FFT(Complex *p,int inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(p[i],p[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
	{
		Complex wn(cos(PI / (double)i),(double)inv * sin(PI / (double)i));
		for (int j = 0;j < N;j += (i << 1))
		{
			Complex w(1,0);
			for (int k = 0;k < i;k++)
			{
				Complex x = p[j + k],y = w * p[j + k + i];
				p[j + k] = x + y;
				p[j + k + i] = x - y;
				w = w * wn;
			}
		}
	}
	if (inv == -1)
	{
		for (int i = 0;i < N;i++)
			p[i] = p[i] / (double)N;
	}
}

void solve(int l,int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		if (a[l])
			ans[1]++;
		else
			ans[0]++;
		return;
	}
	int mid = (l + r) >> 1,cnt = 0;
	la = -1,lb = -1;
	for (int i = mid;i >= l;i--)
	{
		if (!a[i])
			cnt++;
		else
		{
			pa[++la].real = cnt;
			pa[la].imag = 0;
			cnt = 1;
		}
	}
	pa[++la] = cnt;
	pa[la].imag = 0;
	cnt = 0;
	for (int i = mid + 1;i <= r;i++)
	{
		if (!a[i])
			cnt++;
		else
		{
			pb[++lb].real = cnt;
			pb[lb].imag = 0;
			cnt = 1;
		}
	}
	pb[++lb].real = cnt;
	pb[lb].imag = 0;
	if ((ll)la * lb <= 10000)
	{
		for (int i = 0;i <= la;i++)
			for (int j = 0;j <= lb;j++)
				ans[i + j] += (ll)(pa[i].real * pb[j].real + 1e-7);
	}
	else
	{
		N = 1;
		while (N <= la + lb)
			N <<= 1;
		for (int i = 1;i < N;i++)
			rev[i] = (rev[i >> 1] >> 1) + (bool)(i & 1) * (N >> 1);
		for (int i = la + 1;i < N;i++)
			pa[i].real = pa[i].imag = 0;
		for (int i = lb + 1;i < N;i++)
			pb[i].real = pb[i].imag = 0;
		FFT(pa,1);
		FFT(pb,1);
		for (int i = 0;i < N;i++)
			pa[i] = pa[i] * pb[i];
		FFT(pa,-1);
		for (int i = 0;i <= min(n,N - 1);i++)
			ans[i] += (ll)(pa[i].real + 0.5);
	}
	solve(l,mid);
	solve(mid + 1,r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] = (a[i] < x);
	}
	solve(1,n);
	for (int i = 0;i <= n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}