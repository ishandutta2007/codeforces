#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define oo 1000111222
using namespace std;

int n,P,p[1010],cnt[256],C=1;
vector < pair<int,char> > a;
string s;
char ans[1010];

int isPrime(int n)
{
	for (int i=2;i*i<=n;i++)
		if (n%i==0) return 0;
	return 1;
}

int main()
{
	for (int i=2;i<1000;i++)
		if (isPrime(i)) p[P++]=i;
	cin >> s;
	n=s.size();
	for (int i=0;i<n;i++) cnt[int(s[i])]++;
	for (int i=0;i<26;i++) 
		if (cnt[i+97]) a.push_back(make_pair(cnt[i+97],char(i+97)));
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for (int i=0;i<P && p[i]<=n;i++)
		if (p[i]*2>n) C++;
	if (a[0].first<n-C) 
	{
		puts("NO"); return 0;
	}
	a[0].first-=(n-C);
	for (int i=2;i<=n;i++)
		if (!isPrime(i) || i*2<=n) ans[i]=a[0].second;
	for (int i=1,j=0;i<=n;i++)
		if (i==1 || (isPrime(i) && i*2>n))
		{
			if (!a[j].first) j++;
			a[j].first--;
			ans[i]=a[j].second;
		}
	puts("YES");
	for (int i=1;i<=n;i++) cout << ans[i];
	puts("");
}