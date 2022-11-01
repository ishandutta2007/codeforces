#include<bits/stdc++.h>
#define ll long long
#define int long long
inline ll read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
int n,p,a[1000010],ans;
signed main(){
	n=read();p=read();for (int i=1;i<=n;i++)a[i]=(read()+a[i-1])%p;
	for (int i=1;i<=n;i++)ans=max(ans,a[i]+(a[n]-a[i]+p)%p);
	writeln(ans);
}