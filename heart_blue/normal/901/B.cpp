#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class Poly
{
	vector<int> v;
public:
	Poly(int n = 0)
	{
		v.resize(n, 0);
	}
	Poly(vector<int> &v)
	{
		this->v = v;
	}
	int size()
	{
		return v.size();
	}
	bool check()
	{
		for (auto &x : v)
		{
			if (x > 1 || x < -1) return false;
		}
		return true;
	}
	void refrain()
	{
		if (v.back() < 0)
		{
			for (auto &x : v) x = -x;
		}
	}
	Poly operator * (Poly &p)
	{
		Poly ret(p.size() + size() - 1);
		for (int i = 0; i < p.size(); i++)
		{
			for (int j = 0; j < size(); j++)
			{
				ret[i + j] = ret[i + j] + p[i] * v[j];
			}
		}
		ret.refrain();
		return ret;
	}
	Poly operator + (Poly &p)
	{
		Poly ret(max(p.size(), size()));
		for (int i = 0; i < p.size(); i++) ret[i] += p[i];
		for (int i = 0; i < size(); i++) ret[i] += v[i];
		return ret;
	}
	Poly operator - (Poly &p)
	{
		Poly ret(max(p.size(), size()));
		for (int i = 0; i < size(); i++) ret[i] += v[i];
		for (int i = 0; i < p.size(); i++) ret[i] -= p[i];
		return ret;
	}
	int& operator [](int i)
	{
		return v[i];
	}
	void output()
	{
		cout << v.size() - 1 << endl;
		for (auto &x : v) cout << x << ' ';
		cout << endl;
	}
};
vector<Poly> ans1, ans2, ans3, ans;
void check(vector<Poly> &ans, Poly &p0, Poly &p1)
{
	ans.push_back(p0);
	ans.push_back(p1);
	int n = 150;
	vector<int> v = { 0,1 };
	Poly x(v);
	for (int o = 2; o <= n; o++)
	{
		Poly p;
		Poly &p1 = ans[o - 2];
		Poly &p2 = ans[o - 1];
		p = p2*x + p1;
		if (p.check()) ans.push_back(p);
		else
		{
			p = p2*x - p1;
			if (p.check()) ans.push_back(p);
			else return;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v0 = { 1 };
	vector<int> v1 = { 0,1 };
	vector<int> v2 = { -1,1 };
	vector<int> v3 = { 1,1 };
	Poly p0(v0), p1(v1), p2(v2), p3(v3);
	check(ans1, p0, p1);
	check(ans2, p0, p2);
	check(ans3, p0, p3);
	if (ans.size() < ans1.size()) ans = ans1;
	if (ans.size() < ans2.size()) ans = ans2;
	if (ans.size() < ans3.size()) ans = ans3;
	int n;
	cin >> n;
	if (ans.size() < n+1)
	{
		puts("-1");
		return 0;
	}
	ans[n].output();
	ans[n - 1].output();
	return 0;
}