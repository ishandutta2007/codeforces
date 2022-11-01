#include<bits/stdc++.h>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
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

const ll N=100005;
ll n,tab[N];
ll tmp,ans[N];
vector<ll> v[100];
int main()
{
	n=read();
	For(i,1,n)	tab[i]=read();
	For(i,1,n)Dow(j,0,60)if(tab[i]>>j&1){v[j].push_back(tab[i]); break;}
	For(tot,1,n)
	{
		ll flag=0;
		For(i,0,59)
		if((tmp>>i&1)==0&&v[i].size())
		{
			tmp^=(ans[tot]=v[i][v[i].size()-1]); v[i].pop_back(); flag=1; break;
		}
		if(!flag){puts("No"); return 0;}
	}
	puts("Yes");
	For(i,1,n)	{write_p(ans[i]);}
}