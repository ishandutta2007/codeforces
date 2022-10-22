#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,Mod;
#define Maxn 505
#define cout cerr
#define FR first
#define SE second

int f[Maxn],g[Maxn];
int fact[Maxn],inv[Maxn];
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;
pii mul(pii t1,pii t2){return pii(mul(t1.first,t2.first),add(mul(t1.first,t2.second),mul(t1.second,t2.first)));}
void init(){
	fact[0]=1;
	for(int i=1;i<=n;++i)fact[i]=mul(fact[i-1],i);
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	for(int i=2;i<=n;++i)inv[i]=mul(inv[i-1],inv[i]);
}
int sum(int x){return 1ll*x*(x+1)/2%Mod;}
int C(int a,int b){
	if(a<b)return 0;
	return mul(fact[a],mul(inv[a-b],inv[b]));
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

pii ans[Maxn][Maxn];

int main(){
	rd(n);rd(m);rd(Mod);
	init();
	f[0]=1;g[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j){
			int t=C(i-1,j-1);pii tmp=mul(pii(f[j-1],g[j-1]),pii(f[i-j],g[i-j]));
			tmp.FR=mul(tmp.FR,t);tmp.SE=mul(tmp.SE,t);
			tmp=mul(pii(i+1,add(sum(j-1),sum(i-j))),tmp);
			f[i]=add(f[i],tmp.FR);g[i]=add(g[i],tmp.SE);
		}
	ans[0][0]=pii(1,0);
	for(int i=1;i<=n-m+1;++i)
		for(int j=0;j<=n;++j)
			for(int k=0;k<=n-j;++k){
				int t=C(j+k,k);
				pii tmp=mul(ans[i-1][j],pii(f[k],g[k]));
				tmp.FR=mul(tmp.FR,t);tmp.SE=mul(tmp.SE,t);
				ans[i][j+k].FR=add(ans[i][j+k].FR,tmp.FR);
				ans[i][j+k].SE=add(ans[i][j+k].SE,tmp.SE);
			}
	printf("%d\n",ans[n-m+1][m].SE);
	return 0;
}