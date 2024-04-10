#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
ll a[Maxn],b[Maxn];

ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
inline void rd(ll &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)rd(a[i]);
	for(int i=1;i<=m;++i)rd(b[i]);
	for(int i=n;i>=2;--i)a[i]=abs(a[i]-a[i-1]);
	ll res=0;
	for(int i=n;i>=2;--i)res=gcd(res,a[i]);
	for(int i=1;i<=m;++i){
		printf("%lld ",gcd(a[1]+b[i],res));
	}
	return 0;
}