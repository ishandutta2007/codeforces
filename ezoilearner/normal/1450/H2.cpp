#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int inv2=499122177;
typedef long long ll;
typedef pair<int,int> pii;
int n,K,F,m;int A,B,ans;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];int base[Maxn],two[Maxn];

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
	if(b<0)return 0;
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
	base[0]=1;two[0]=1;
	for(int i=1;i<=n;++i)base[i]=mul(base[i-1],inv2),two[i]=add(two[i-1],two[i-1]);
}

void mr(){B++;ans=add(ans,C(A,B));}
void ml(){ans=dec(ans,C(A,B));B--;}
void mu(){
	int tmp=dec(ans,C(A,B));
	ans=add(ans,tmp);
	A++;
}
void md(){
	A--;
	ans=add(ans,C(A,B));
	ans=mul(ans,inv2);
}
void mv(int a,int b){
	for(int i=A;i>a;--i)md();
	for(int i=A;i<a;++i)mu();
	for(int i=B;i<b;++i)mr();
	for(int i=B;i>b;--i)ml();
}
int S(int a,int b){
	if(a<0||b<0)return 0;
	mv(a,b);
	return ans;
}

void solve(){
	int t1=S(F-1,K-2);
	int t2=S(F-2,K-3);
	if(F==1&&K>=3&&(K-3)%2==0)t2=1;
	int res=dec(mul(t1,K),mul(t2,F));
	if(F>=2)t2=dec(two[F-2],t2);
	else if(K<=1&&(K-1)%2==0)t2=1;
	else t2=0;
	res=add(res,mul(t2,F));
	t1=dec(two[F-1],t1);
	res=dec(res,mul(t1,K));
	res=mul(res,base[F]);
	printf("%d\n",res);
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
char opt[5];int pos;

int main(){
	rd(n);K=n/2;rd(m);
	scanf("%s",ch+1);
	init();
	for(int i=1;i<n;i+=2){
		if(ch[i]=='b')K--;
		if(ch[i+1]=='w')K--;
		if(ch[i]=='?')F++;
		if(ch[i+1]=='?')F++;
	}
	A=0;B=0;ans=1;
	solve();
	while(m--){
		rd(pos);
		scanf("%s",opt);
		if(ch[pos]=='?')F--;
		if((pos&1)&&ch[pos]=='b')K++;
		if((pos%2==0)&&ch[pos]=='w')K++;
		ch[pos]=opt[0];
		if(ch[pos]=='?')F++;
		if((pos&1)&&ch[pos]=='b')K--;
		if((pos%2==0)&&ch[pos]=='w')K--;
		solve();
	}
	return 0;
}