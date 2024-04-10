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

int n,d[11],ans1,ans2,e[11],r1[100100],r2[100100],R1[100100],R2[100100];
char s[200000];

int calc(int x,int y,int d[],int e[],int &zeroLeft)
{
	zeroLeft=0;
	if (!d[x]) return 0;
	d[x]--;
	if (!e[y]) return 0;
	e[y]--;
	int res=1;
	fr(i,0,9) 
	{
		int t=min(d[i],e[9-i]);
		res+=t;
		d[i]-=t; e[9-i]-=t;
	}
	zeroLeft=min(d[0],e[0]);
	res+=zeroLeft;
	return res;
}

void put(int r1[],int r2[],int st,int x,int y,int d[],int e[],int zeroLeft)
{
	while (zeroLeft--) r1[st]=0, r2[st++]=0, d[0]--, e[0]--;
	if (d[x] && e[y])
	{
		d[x]--; e[y]--;
		r1[st]=x; r2[st++]=y;
	}
	fr(i,0,9) 
		while (min(d[i],e[9-i])>0)
		{
			d[i]--; e[9-i]--;
			r1[st]=i; r2[st++]=9-i;
		}
	int st1=st,st2=st;
	fr(i,0,9)
		while (d[i]--) r1[st1++]=i;
	fr(i,0,9)
		while (e[i]--) r2[st2++]=i;
}

int zeroRightmost(int d[])
{
	int res=d[0],best=-1,save=-1,e[11]={0},ee[11]={0},zz;
	fr(i,1,5)
	{
		fr(j,1,9) e[j]=ee[j]=d[j];
		e[0]=ee[0]=0;
		int x=calc(i,10-i,e,ee,zz);
		if (x>best) best=x, save=i;
	}
	res+=best;
	fr(i,1,9) e[i]=ee[i]=d[i];
	put(r1,r2,d[0],save,10-save,e,ee,0);
	return res;
}

int notZeroRightmost(int d[])
{
	int res=-1,save=-1,e[11],ee[11],zeroLeft=0,zz;
	fr(i,1,5)
	{
		rep(j,10) e[j]=ee[j]=d[j];
		int x=calc(i,10-i,e,ee,zz);
		if (x>res) res=x, save=i, zeroLeft=zz;
	}
	rep(i,10) e[i]=ee[i]=d[i];
	put(R1,R2,0,save,10-save,e,ee,zeroLeft);
	return res;
}

int main()
{
	rep(i,10) d[i]=0;
	scanf("%s",&s);
	n=strlen(s);
	rep(i,n) d[s[i]-'0']++;
	rep(i,10) e[i]=d[i];
	ans1=zeroRightmost(e);
	rep(i,10) e[i]=d[i];
	ans2=notZeroRightmost(e);
	if (ans1>=ans2)
	{
		repp(i,n) printf("%d",r1[i]); puts("");
		repp(i,n) printf("%d",r2[i]); puts("");
	}
	else
	{
		repp(i,n) printf("%d",R1[i]); puts("");
		repp(i,n) printf("%d",R2[i]); puts("");
	}
}