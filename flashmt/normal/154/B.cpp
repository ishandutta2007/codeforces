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
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,m,d[100100],p[100100],P,e[100100],pp[100100];
int divisors[10],D;

void sieve()
{
	for (int i=2;i*i<=100000;i++)
		if (!d[i]) 
			for (int j=i*i;j<=100000;j+=i)
				d[j]=-1;
	for (int i=2;i<=100000;i++)
		if (!d[i]) p[++P]=i, d[i]=P;
}

void factorize(int n)
{
	D=0;
	if (d[n]>0) 
	{
		divisors[D++]=d[n];
		return;
	}
	
	for (int i=1;i<=P && p[i]*p[i]<=n && n>1;i++)
		if (n%p[i]==0)
		{
			divisors[D++]=i;
			while (n%p[i]==0) n/=p[i];
		}
	if (n>1) divisors[D++]=d[n];
}

int check()
{
	for (int i=0;i<D;i++)
		if (pp[divisors[i]]) return pp[divisors[i]];
	return 0;
}

void turn(int val)
{
	for (int i=0;i<D;i++) pp[divisors[i]]=val;
}

int main()
{
	sieve();
	cin >> n >> m;
	while (m--)
	{
		string s;
		int x;
		cin >> s >> x;
		factorize(x);
		if (s=="+")
		{
			if (e[x]) puts("Already on");
			else
			{
				int y=check();
				if (!y) turn(x), puts("Success"), e[x]=1; 
				else printf("Conflict with %d\n",y);
			}
		}
		else 
		{
			if (e[x]) turn(0), puts("Success"), e[x]=0;
			else puts("Already off");
		}
	}
}