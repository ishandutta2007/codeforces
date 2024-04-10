#include<bits/stdc++.h>
#define ll long long
#define N 1000010
inline ll read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int n,mp[205][205],p[N],q[N];
signed main(){
	n=read();
	for(int i = 1;i <= n;++i){
		int x = read(),y = read(),z = read();
		int k = x+y,Gcd = gcd(k,z); k /= Gcd,z /= Gcd;
		mp[k][z]++;
		p[i]=k;q[i] = z;
	}
	for(int i = 1;i <= n;++i) printf("%d ",mp[p[i]][q[i]]);
}