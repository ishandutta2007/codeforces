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

const int N=300005;
int n,a[N],ans,inv[N];
ll mo=998244353;
int main(){
	n=read();
	For(i,1,2*n)	a[i]=read();
	sort(a+1,a+2*n+1);
	For(i,1,n)
		ans=(ans-a[i]+mo)%mo;
	For(i,n+1,2*n)
		ans=(ans+a[i])%mo;
	Dow(i,n+1,2*n)
		ans=1LL*ans*i%mo;
	inv[1]=1;
	For(i,2,n)
		inv[i]=1LL*inv[mo%i]*(mo-mo/i)%mo;
	For(i,2,n)
		ans=1LL*ans*inv[i]%mo;
	writeln(ans);
}