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
const int Mod=998244353;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

int n,K;
#define Maxn 200010

int p[Maxn],mu[Maxn];
bool vis[Maxn];
int fact[Maxn],ifac[Maxn],inv[Maxn];
void init(){
	mu[1]=1;
	rep(i,2,n){
		if(!vis[i]){
			p[++p[0]]=i;
			mu[i]=-1;
			cout<<"i "<<i<<endl;
		}
		for(int j=1;j<=p[0]&&1ll*i*p[j]<=n;++j){
			vis[i*p[j]]=true;
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	fact[0]=1;rep(i,1,n)fact[i]=mul(fact[i-1],i);
	inv[0]=inv[1]=1;rep(i,2,n)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	ifac[0]=1;rep(i,1,n)ifac[i]=mul(ifac[i-1],inv[i]);
}

int Ans=0;

int s1[Maxn],s2[Maxn],ans[Maxn],cnt=0;
int a[Maxn];

int F[Maxn],p1[Maxn],p2[Maxn];
const int B=450;
void init(int z){
	p1[0]=1;rep(i,1,B)p1[i]=mul(p1[i-1],z);
	int b=p1[B];
	p2[0]=1;rep(i,1,n/B)p2[i]=mul(p2[i-1],b);
}

void search(int u){
	init(u);
	rep(i,1,cnt)ans[i]=add(ans[i],mul(mul(p1[s1[i]%B],p2[s1[i]/B]),a[u]));
}

int main(){
	rd(n);rd(K);K=min(n,K);
	if(K==1){
		puts("1");
		return 0;
	}
	init();
	rep(i,1,n){
		if(!cnt||s1[cnt]!=(n-1)/i+1)s1[++cnt]=(n-1)/i+1;
		if(mu[i]>0)s2[cnt]=add(s2[cnt],1);else if(mu[i]<0)s2[cnt]=dec(s2[cnt],1);
	}
	int sum=0;
	per(i,K,0){
		if((K-i)&1)sum=dec(sum,ifac[K-i]);
		else sum=add(sum,ifac[K-i]);
		a[i]=mul(sum,ifac[i]);
	}
	rep(i,0,K)search(i);
	rep(i,1,cnt)Ans=add(Ans,mul(s2[i],ans[i]));
	rep(i,1,n)
		if(mu[i]>0)Ans=dec(Ans,1);
		else if(mu[i]<0)Ans=add(Ans,1);
	printf("%d\n",Ans);
	return 0;
}