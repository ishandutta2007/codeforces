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

const int N = 2e6+5;

int mo = 1e9 + 7; 
int n, sum[N], ans, c[N];
ll rev[N], fac[N];
ll tot, tot_val;

inline ll ksm(ll x,ll y){ll ret = 1; for(; y; y /= 2, x = x * x % mo)	if(y & 1)	ret = ret * x % mo; return ret;}
int main()
{
	n = read();
	For(i, 1, n)
		c[i] = read(), tot += c[i], sum[1000000 + c[i] - 1]++, sum[1000000 - (c[i] - 1) - 2]--;
	fac[0] = 1;
	tot %= mo;
	For(i, 1, 1000000)	fac[i] = fac[i - 1] * i % mo;
	rev[1000000] = ksm(fac[1000000], mo - 2);
	Dow(i, 0, 999999)	rev[i] = rev[i + 1] * (i + 1) % mo;
	ll ans = 1;
	ll rev2 = ksm(2, mo - 2);
	Dow(i, 0, 2000000) 
	{
		// if(sum[i])	cout << sum[i] <<' '<<fac[sum[i]]<<' '<<ans<<endl;
		ans = ans * fac[sum[i]] % mo;
		tot_val += (tot + (tot - sum[i] + 1)) * sum[i] % mo * rev2 % mo * (i - 1000000) % mo;
		tot_val %= mo; tot_val += mo;tot_val %= mo;
		tot -= sum[i];
		sum[i - 2] += sum[i];
	}	
	write_p(tot_val);
	writeln(ans);
}