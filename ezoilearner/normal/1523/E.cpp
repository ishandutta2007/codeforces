#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
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

int n,K;
#define Maxn 200010
int h[Maxn];

const int Mod=1000000007;

int add(int a,int b){
	return a+b>=Mod?a+b-Mod:a+b;
}
int mul(int a,int b){return 1ll*a*b%Mod;}

int inv[Maxn],fact[Maxn],ifac[Maxn];
void init(){
	n=100000;
	fact[0]=1;rep(i,1,n)fact[i]=mul(i,fact[i-1]);
	inv[0]=inv[1]=1;rep(i,2,n)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	ifac[0]=1;rep(i,1,n)ifac[i]=mul(ifac[i-1],inv[i]);
}

int C(int a,int b){
	if(a<b||b<0)return 0;
	return mul(fact[a],mul(ifac[b],ifac[a-b]));
}

int main(){
	init();
	int T;
	rd(T);
	while(T--){
		rd(n);rd(K);
		int res=1;
		rep(i,1,n){
			if(1ll*(i-1)*(K-1)>n-i)break;
			int t=n-i-(i-1)*(K-1);
			res=add(res,mul(mul(mul(C(t+i,i),ifac[n]),fact[i]),fact[n-i]));
		}
		printf("%d\n",res);
	}
	return 0;
}