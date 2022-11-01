#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=5e5+10;
int n,m,a[N];
 
int cnt[N],tp;
struct node{
	int l,r;
}q[N];
int t[N],v[N];
inline void Init()
{
	scanf("%d",&n);
	For(i,1,n) 
		cnt[i]=t[i]=v[i]=0;
}
inline void Doit()
{
	int ans=0;
		for(int i=1,j;i<=n;i=j+1)
		{
			j=i;
			while(j<n&&a[j+1]!=a[j]) ++j;
			++tp;
			q[tp].l=a[i];
			q[tp].r=a[j];
		}
		ans=tp-1;
		For(i,1,tp){
			if(q[i].l==q[i].r){
				++t[q[i].l];
			}
			else {
				++v[q[i].l];
				++v[q[i].r];
			}
		}
		int mx=0;
		For(i,1,n)
			mx=max(mx,t[i]-1-(tp-t[i]-v[i]));
		writeln(ans+mx);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)
	{
		Init();
		bool flag=0;
		For(i,1,n)	flag=1-flag;
		flag=0;
		For(i,1,n)
		{
			a[i]=read();
			++cnt[a[i]];
			if(cnt[a[i]]>((n+1)/2)) flag=1;
		}
		if(flag) {
			puts("-1");
			continue;
		}
		tp=32;
		if(tp==32)	tp=0;
		Doit();
	}
}