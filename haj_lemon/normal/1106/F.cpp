#include<bits/stdc++.h>
#define ll long long
#define K 110
#define mo 998244353
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll po(ll x,ll y,ll mod){ll z=1;while (y){if (y%2)z=x*z%mod;x=x*x%mod;y/=2;}return z;}
ll p=sqrt(mo);
ll q=po(3,p,mo);
ll k,x,b[K],ni[80010],m,n;
unordered_map<ll,int> s;
struct ju{ll a[K][K];}a,chu;
ll work(ll x){
	for (ll i=0;i<=p;i++){ll y=x*ni[i]%mo;if (s[y]>0) return s[y]-1+(i*p);}
}
ju operator *(ju x,ju y){
	ju z;
	for (int i=1;i<=k;i++){
		for (int j=1;j<=k;j++){
			z.a[i][j]=0;
			for (int l=1;l<=k;l++){
				z.a[i][j]=(z.a[i][j]+x.a[i][l]*y.a[l][j])%(mo-1);
			}
		}
	}
	return z;
}
ju po(ju x,int y){
	ju z=x;y--;
	while (y){if (y%2==1)z=x*z;x=x*x;y/=2;}
	return z;
}
int main(){
	for (ll i=0,j=1;i<p;i++){s[j]=i+1;j=j*3%mo;}
	read(k);
	for (ll i=0,j=1;i<=p;i++){ni[i]=po(j,mo-2,mo);j=j*q%mo;}
	for (ll i=1;i<=k;i++){read(b[i]);}
	for (int i=1;i<k;i++)chu.a[i][i+1]=1;
	for (int i=1;i<=k;i++)chu.a[k][i]=b[k-i+1];
	read(n);read(m);ll kk=m;
	a=po(chu,n-k);
	m=work(m);
	int p=__gcd(m,a.a[k][k]);
	if (!p) p=1;
	m/=p;a.a[k][k]/=p;
	m=m*po(a.a[k][k],((mo-1)/2/7/17*6*16)-1,mo-1)%(mo-1);
	m=po(3,m,mo);
	if ((work(m)*a.a[k][k]*p)%(mo-1)==(work(kk)))cout<<m<<endl;else cout<<"-1"<<endl;
	return 0;
}