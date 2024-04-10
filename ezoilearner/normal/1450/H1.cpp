#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
typedef long long ll;
typedef pair<int,int> pii;
int n,K,t;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];

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
int fact[Maxn],ifac[Maxn],inv[Maxn];

int C(int a,int b){
	if(a<b)return 0;
	return mul(fact[a],mul(ifac[b],ifac[a-b]));
}
void init(){
	fact[0]=1;
	for(int i=1;i<=n;++i)fact[i]=mul(i,fact[i-1]);
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	ifac[0]=1;
	for(int i=1;i<=n;++i)ifac[i]=mul(ifac[i-1],inv[i]);
}

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
	rd(n);K=n/2;rd(t);
	scanf("%s",ch+1);
	init();
	int Ans=0,m=0;
	for(int i=1;i<n;i+=2){
		if(ch[i]=='b')K--;
		if(ch[i+1]=='w')K--;
		if(ch[i]=='?')m++;
		if(ch[i+1]=='?')m++;
	}
	for(int i=0;i<=m;++i){
		int t=max(i-K,K-i);
		if(t%2==0)Ans=add(Ans,mul(t/2,C(m,i)));
	}
	Ans=mul(Ans,Fast_Pow(2,1ll*(m-1)*(Mod-2)%(Mod-1)));
	printf("%d\n",Ans);
	return 0;
}