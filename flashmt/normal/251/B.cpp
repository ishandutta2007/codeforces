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
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int equal(int a[],int s[],int n)
{
	fr(i,1,n)
		if (a[i]!=s[i]) return 0;
	return 1;
}

int main()
{
	int p[111],s[111],a[111],invp[111],n,k,pos=0,neg=0,tmp[111];
	cin >> n >> k;
	fr(i,1,n) cin >> p[i];
	fr(i,1,n) invp[p[i]]=i;
	fr(i,1,n) cin >> s[i];
	
	fr(j,1,n) a[j]=j;
	if (equal(a,s,n))
	{
		puts("NO");
		return 0;
	}
	
	fr(i,1,k)
	{
		fr(j,1,n) tmp[j]=a[j];
		fr(j,1,n) a[j]=tmp[p[j]];
		if (equal(a,s,n))
		{
			pos=i; break;
		}
	}
	
	fr(j,1,n) a[j]=j;
	fr(i,1,k)
	{
		fr(j,1,n) tmp[j]=a[j];
		fr(j,1,n) a[j]=tmp[invp[j]];
		if (equal(a,s,n))
		{
			neg=i;
			break;
		}
	}

	if (pos==1 && neg==1 && k>1)
	{
		puts("NO");
		return 0;
	}

	if (pos)
	{
		if (k%2==pos%2)
		{
			puts("YES");
			return 0;
		}
	}
	
	if (neg)
	{
		if (k%2==neg%2)
		{
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
}