#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
inl int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int MAXN = 4e5+10;
int n,a[MAXN],ans=1,Gcd;
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
signed main(){
	n=read();
	Gcd=a[1]=read();
	for(int i=2;i<=n;i++) a[i]=read(),Gcd=gcd(Gcd,a[i]);
	for(int i=2;i*i<=Gcd;i++){
		if(Gcd%i==0){
			int res=0;
			while(Gcd%i==0) Gcd/=i,res++;
			ans*=(res+1);
		}
	}if(Gcd!=1) ans*=2;
	cout<<ans;
	return 0;
}