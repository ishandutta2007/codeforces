#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int D2=998244351;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)
int m,n;
#define cout cerr
#define Maxn 300010
#define FR first
#define SE second
int a[Maxn];
int inv[Maxn];
int f[Maxn];

namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			a=1ll*a*a%Mod;
			b>>=1;
		}
		return res;
	}
}using namespace modular;


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

int main(){
	rd(n);
	rep(i,1,n)rd(a[i]),m+=a[i];
	inv[0]=inv[1]=1;
	rep(i,2,m)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	f[0]=f[1]=1;
	int _n=Fast_Pow(n-1,Mod-2);
	rep(a,1,m-1){
		f[a+1]=mul(dec(1,mul(mul(m-a,n-2),mul(_n,inv[m]))),f[a]);
		f[a+1]=dec(f[a+1],mul(mul(a,inv[m]),f[a-1]+1));
		f[a+1]=mul(mul(f[a+1],inv[m-a]),mul(m,n-1));
	}
	int res=dec(0,add(f[m],n-1));
	rep(i,1,n)res=add(res,f[a[i]]);
	printf("%d\n",res);
	return 0;
}