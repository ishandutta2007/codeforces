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

int n;
#define Maxn 400010
int fa[Maxn];
int getroot(int x){
	if(fa[x]^x)fa[x]=getroot(fa[x]);
	return fa[x];
}

const int Mod=1000000007;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			b>>=1;
			a=1ll*a*a%Mod;
		}
		return res;
	}
}using namespace modular;

int p1[Maxn],p2[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		rep(i,1,n){
			fa[i]=i;
			rd(p1[i]);
		}
		rep(i,1,n){
			rd(p2[i]);
			int x=getroot(p1[i]),y=getroot(p2[i]);
			fa[x]=y;
		}
		int cnt=0;
		rep(i,1,n){
			getroot(i);
			if(fa[i]==i)cnt++;
		}
		printf("%d\n",Fast_Pow(2,cnt));
	}
	return 0;
}