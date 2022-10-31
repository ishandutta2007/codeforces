#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<map>
#include<fstream>
#include<set>
#include <functional>
#include <queue>
using namespace std;

template<int mod, int maxn>class Mint;
template<int mod, int maxn>Mint<mod, maxn>inv(Mint<mod, maxn>m);
template<int mod, int maxn>Mint<mod, maxn>fact(int n);
template<int mod, int maxn>Mint<mod, maxn>ofact(int n);
template<class T> T sqr(T x)
{
	return x * x;
}
template<int mod, int maxn>class Mint {
	int a;
public:
	void rev()
	{
		a = mod - a;
	}
	Mint rever()
	{
		return mod - a;
	}
	Mint(int);
	Mint(long long);
	Mint& operator+=(Mint& m) {
		a += m.a;
		if (a >= mod)
			a -= mod;
		return *this;
	}
	Mint& operator+=(int m) {
		a += m;
		if (a >= mod)
			a -= mod;
		return *this;
	}
	Mint& operator-=(Mint& m)
	{
		m.rev();
		a += m.a;
		if (a >= mod)
			a -= mod;
		m.rev();
		return *this;
	}
	bool operator==(Mint& m)
	{
		return (a == m.a);
	}
	bool operator!=(Mint& m)
	{
		return (a != m.a);
	}
	bool operator==(int m)
	{
		return (a == m);
	}
	bool operator!=(int m)
	{
		return (a != m);
	}
	Mint& operator*=(Mint m) {
		long long xx = a * 1LL * m.a;
		xx %= mod;
		a = xx;
		return *this;
	}
	Mint& operator*=(int m) {
		long long xx = a * 1LL * m;
		xx %= mod;
		a = xx;
		return *this;
	}
	Mint& operator/=(Mint mm) {
		long long val = a * 1LL * inv(mm).a;
		val %= mod;
		a = val;
		return *this;
	}
	Mint& operator/=(int m) {
		Mint mm = m;
		long long val = a * 1LL * inv(mm).a;
		val %= mod;
		a = val;
		return *this;
	}
	int eval() {
		return a;
	}
};
template<int mod, int maxn>Mint<mod, maxn> operator +(Mint<mod, maxn>m1, Mint<mod, maxn>m2)
{
	Mint<mod, maxn> x = m1;
	return x += m2;
}
template<int mod, int maxn>Mint<mod, maxn> operator +(Mint<mod, maxn>m1, int m2)
{
	Mint<mod, maxn> x = m1;
	return x += m2;
}
template<int mod, int maxn>ostream& operator <<(ostream& oo, Mint<mod, maxn>m2)
{
	return oo << m2.eval();
}
template<int mod, int maxn>istream& operator >>(istream& ii, Mint<mod, maxn>m2)
{
	return ii >> m2.eval();
}
template<int mod, int maxn>Mint<mod, maxn> operator -(Mint<mod, maxn>m1, Mint<mod, maxn>m2)
{
	Mint<mod, maxn> x = m1;
	return x -= m2;
}
template<int mod, int maxn>Mint<mod, maxn> operator *(Mint<mod, maxn>m1, Mint<mod, maxn>m2)
{
	Mint<mod, maxn> x = m1;
	return x *= m2;
}
template<int mod, int maxn>Mint<mod, maxn> operator *(Mint<mod, maxn>m1, int m2)
{
	Mint<mod, maxn> x = m1;
	return x *= m2;
}
template<int mod, int maxn>Mint<mod, maxn> operator /(Mint<mod, maxn>m1, Mint<mod, maxn>m2)
{
	Mint<mod, maxn> x = m1;
	return x /= m2;
}
template<int mod, int maxn>Mint<mod, maxn> operator /(Mint<mod, maxn>m1, int m2)
{
	Mint<mod, maxn> x = m1;
	return x /= m2;
}
template<int mod, int maxn>Mint<mod, maxn>::Mint(int x)
{
	a = x;
}
template<int mod, int maxn>Mint<mod, maxn>::Mint(long long x)
{
	a = x % mod;
}
template<class T> T bp(T m, int x)
{
	if (x == 0)
		return 1;
	return (x % 2) ? bp(m, x - 1) * m : sqr(bp(m, x / 2));
}
template<int mod, int maxn>Mint<mod, maxn>inv(Mint<mod, maxn>m)
{
	class Zerodiv {};
	static vector<Mint<mod, maxn>>invs(maxn, 0);
	int q = m.eval();
	if (q == 0)
		throw(Zerodiv{});
	if (q >= maxn)
		return bp(m, mod - 2);
	else
	{
		invs[1] = 1;
		if (invs[q] != 0)
			return invs[q];
		Mint<mod, maxn> val = mod / q;
		val.rev();
		val *= inv<mod, maxn>(mod % q);
		invs[q] = val;
		return val;
	}
}
template<int mod, int maxn>Mint<mod, maxn>fact(int n)
{
	//cout << "FACT " << n << endl;
	class Range_error {};
	static vector<Mint<mod, maxn>>facts(maxn, 0);
	if (facts[0] == 0)
		facts[0] = 1;
	try {
		if (n >= mod)
			return 0;
		if (n < 0 || n >= maxn)
			throw(Range_error{});
		if (facts[n] != 0)
			return facts[n];
		else
		{
			Mint<mod, maxn> val = fact<mod, maxn>(n - 1) * n;
			facts[n] = val;
			return val;
		}
	}
	catch (Range_error) {
		cout << "Wrong range";
		abort();
	}
}
template<int mod, int maxn>Mint<mod, maxn>ofact(int n)
{
	//cout << n << endl;
	class Range_error {};
	class Zero_div { };
	static vector<Mint<mod, maxn>>ofacts(maxn, 0);
	if (ofacts[maxn - 1] == 0)
		ofacts[maxn - 1] = inv<mod, maxn>(fact<mod, maxn>(maxn - 1));
	try {
		if (n >= mod)
			throw(Zero_div{});
		if (n < 0 || n >= maxn)
			throw(Range_error{});
		if (ofacts[n] != 0)
			return ofacts[n];
		else
		{
			Mint<mod, maxn> val = ofact<mod, maxn>(n + 1) * (n + 1);
			ofacts[n] = val;
			//	cout << "ofact " << n << ' ' <<' '<<fact<mod, maxn>(n)<<' '<< val * fact<mod, maxn>(n) << endl;
			return val;
		}
	}
	catch (Range_error) {
		cout << "Wrong range";
		abort();
	}
	catch (Zero_div) {
		cout << "Division by zero";
		abort();
	}
}
template<int mod, int maxn>Mint<mod, maxn>C(int a, int b)
{
	class Range_error {};
	try {
		if (b < a || a < 0)
			throw(Range_error{});
		return ofact<mod, maxn>(a) * ofact<mod, maxn>(b - a) * fact<mod, maxn>(b);
	}
	catch (Range_error)
	{
		cout << "Wrong range in C ";
		abort();
	}

}
const int m1 = 31607, mn1 = 31606;
typedef Mint<m1, mn1> MINT;
int ibit(int n, int i)
{
	return ((n >> i) & 1);
}
MINT sl(vector<vector<MINT>>&matr)
{
	MINT cur = 0;
	int n = matr.size();
	MINT pros = 1;
	vector<vector<MINT>>m1(n, vector<MINT>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pros = pros*matr[i][j];
			m1[i][j] = (MINT)1/matr[i][j];
		//	cerr << i << ' ' << j << ' ' << m1[i][j] << endl;
		}
	}
	vector<vector<MINT>>ps(n,vector<MINT>(1 << n,1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < (1 << j); h++)
			{
				ps[i][h + (1 << j)] = ps[i][h]* m1[i][j];
				//cout << i << ' ' << h + (1 << j) << ' ' << ps[i][h + (1 << j)]<<endl;
			}
		}
	}
	//cout << endl;
	for (int mask = 0; mask < (1 << n); mask++)
	{
			int c = 0;
			MINT val = 1;
			for (int j = 0; j < n; j++)
			{
				if (ibit(mask, j))
				{
					c++;
				}
				val *=(MINT)1-ps[j][mask];
			}
			if (c % 2 == 0)
				cur += val;
			else
				cur -= val;
	}
	//cout << mlt(16*pros,cur) << endl;
	return pros*cur;
}
int main()
{
	int n=21;
	cin >> n;
	vector<vector<MINT>>matr(n, vector<MINT>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int x=143+i;
			cin >> x;
			MINT q = x;
			q/=(MINT)10000;
			matr[i][j] = q;
		}
	//cout << clock() << endl;
	vector<vector<MINT>>matr1 = matr, matr2 = matr, matr3 = matr;
	MINT p1 = 1, p2 = 1, p3 = 1;
	for (int i = 0; i < n; i++)
	{
		matr1[i][i] = 1;
		matr3[i][i] = 1;
		p1 *=matr[i][i];
		p3 *=matr[i][i];
	}
	for (int i = 0; i < n; i++)
	{
		matr2[i][n-1-i] = 1;
		matr3[i][n-1-i] = 1;
		p2 *=matr[i][n-1-i];
		if(i!=n-1-i)
		   p3 *=matr[i][n-1-i];
	}
	MINT cur = 0;
	//cout << p1 << ' ' << p2 << ' ' << p3 << endl;
	cur=cur-p1*sl(matr1);
	cur = cur - p2 * sl(matr2);
	cur = cur + p3 * sl(matr3);
	cur = cur+sl(matr);
	cur = (MINT)1 - cur;
	cout << cur << endl;
//	cout << clock() << endl;
}