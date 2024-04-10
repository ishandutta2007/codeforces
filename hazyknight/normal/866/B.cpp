#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 100005;

struct Con
{
	long long p,a,b;
	bool operator < (const Con & p)const
	{
		return a - b > p.a - p.b;
	}
}con[MAXN];

long long n,s;

long long getp(long long p)
{
	return p / s + (p % s != 0);
}

int main()
{
	cin >> n >> s;
	long long sigma = 0;
	for (int i = 1;i <= n;i++)
		cin >> con[i].p >> con[i].a >> con[i].b,sigma += con[i].p;
	long long lim = getp(sigma);
	sort(con + 1,con + n + 1);
	long long cnta = 0,cntb = 0,ans = 0,bound = 0;
	for (int i = 1;i <= n;i++)
		if (con[i].a >= con[i].b)
			bound++,cnta += con[i].p,ans += con[i].p * con[i].a;
		else
			cntb += con[i].p,ans += con[i].p * con[i].b;
//	cout << cnta << ' ' << cntb << endl;
	long long tmpa = cnta,tmpb = cntb,ans1 = ans,bb = bound;
//	cout << lim << ' ' << getp(cnta) << ' ' << getp(cntb) << endl;
	while (getp(tmpa) + getp(tmpb) > lim)
	{
	//	cout << ans1 << ' ' << tmpa << ' ' << tmpb << endl;
		if (tmpa % s <= con[bb].p)
			ans1 += (tmpa % s) * (con[bb].b - con[bb].a),tmpa -= tmpa % s,tmpb += tmpa % s;
		else
			ans1 += con[bb].p * (con[bb].b - con[bb].a),tmpa -= con[bb].p,tmpb += con[bb].p;
		bb--;
	}
	tmpa = cnta,tmpb = cntb,bb = bound + 1;
	long long ans2 = ans;
	while (getp(tmpa) + getp(tmpb) > lim)
	{
		if (tmpb % s <= con[bb].p)
			ans2 += (tmpb % s) * (con[bb].a - con[bb].b),tmpa += tmpb % s,tmpb -= tmpb % s;
		else
			ans2 += con[bb].p * (con[bb].a - con[bb].b),tmpa += con[bb].p,tmpb -= con[bb].p;
		bb++;
	}
//	cout << ans1 << ' ' << ans2 << endl;
	cout << max(ans1,ans2) << endl;
	return 0;
}