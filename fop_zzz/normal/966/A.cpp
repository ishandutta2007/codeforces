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
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}

int l[200005],r[200005];


signed main()
{
	int n=read(),m=read(),tp=read(),ce=read(),v=read();
	For(i,1,tp)
		l[i]=read();
	sort(l+1,l+tp+1);
	For(i,1,ce)	r[i]=read();
	sort(r+1,r+ce+1);
	
	int q=read();
	
	
	For(TTTT,1,q) 
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (x1==x2){writeln(abs(y1-y2));continue;}
		if (x1>x2)	swap(x1,x2);
		if (y1>y2)	swap(y1,y2);
		int a=lower_bound(l+1,l+tp+1,y1)-l-1,b=upper_bound(l+1,l+tp+1,y2)-l;
		int ans=1e9;
		if (a<b-1)	ans=min(ans,x2-x1+y2-y1);
		else
		{
			if (a)ans=min(ans,x2-x1+y1-l[a]+y2-l[a]);
			if (b!=tp+1)ans=min(ans,x2-x1+2*l[b]-y1-y2);
		}
		a=lower_bound(r+1,r+ce+1,y1)-r-1;
		
		b=upper_bound(r+1,r+ce+1,y2)-r;
		if (a<b-1) ans=min(ans,(x2-x1-1)/v+1+y2-y1);
		else 
		{
			if (a)ans=min(ans,(x2-x1-1)/v+1+y1-r[a]+y2-r[a]);
			if (b!=ce+1)	ans=min(ans,(x2-x1-1)/v+1+2*r[b]-y1-y2);
		}
		writeln(ans);
	}
}