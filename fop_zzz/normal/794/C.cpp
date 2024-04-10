#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define local freopen("in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read()
{
	ll t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

char s1[500001],s2[500001],ans[500001];
int main()
{
	scanf("\n%s",s1+1);scanf("\n%s",s2+1);
	int len=strlen(s1+1);
	sort(s1+1,s1+len+1);sort(s2+1,s2+len+1);
	reverse(s2+1,s2+len+1);
	int t1=1,t2=len;
	int l1=1,l2=1,r1=(len+1)/2,r2=(len)/2,l=1,r=len;
	For(i,1,len)
	{
		if(i&1)	
			if(s1[l1]<s2[l2])
				ans[l]=s1[l1],l++,l1++;
				else	ans[r]=s1[r1],r--,r1--;
		else
			if(s1[l1]<s2[l2])
				ans[l]=s2[l2],l++,l2++;
				else	ans[r]=s2[r2],r--,r2--;
	}
	For(i,1,len)	putchar(ans[i]);
}