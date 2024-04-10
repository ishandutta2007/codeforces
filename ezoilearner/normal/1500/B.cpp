#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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

int n,m,g;ll K;
#define Maxn 500010
int a[Maxn],b[Maxn];
ll Mod,h1,h2;

int mod[Maxn<<1],cnt=0;
vector<ll> A[Maxn<<1],B[Maxn<<1];
int vis[Maxn<<1];

ll gao(int u,ll v){
//	<=v-i
//	>=Mod-i
	int at=B[u].size()-1;
	ll ans=0;
	for(int i=0;i<A[u].size();++i){
		while(at>=0&&A[u][i]+B[u][at]>v)at--;
		ans+=at+1;
	}
	return ans;
}
ll H[Maxn<<1];
ll calc(ll mid){
	ll res=mid+1; 
	rep(i,1,cnt)
	if(A[i].size()>0&&B[i].size()>0){
		if(mid<mod[i])continue;
		ll v=(mid-mod[i])/g;
		res-=v/Mod*(ll)A[i].size()*(ll)B[i].size();
		v%=Mod;
		res-=gao(i,v)+gao(i,Mod+v)-H[i];	
	}
	return res;
}

int inv(int x,int y){
	if(y==1)return 0;
	for(int i=0;i<y;++i)
		if(1ll*x*i%y==1)return i; 
}

void init(int u){
	for(int i=0;i<A[u].size();++i)A[u][i]=1ll*A[u][i]*h1%Mod;
	for(int i=0;i<B[u].size();++i)B[u][i]=1ll*B[u][i]*h2%Mod;
	sort(A[u].begin(),A[u].end());sort(B[u].begin(),B[u].end());
}

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b); 
}

int main(){
	rd(n);rd(m);g=gcd(n,m);scanf("%lld",&K);
	Mod=1ll*n*m/g/g;
	h1=1ll*m/g*inv(m/g,n/g)%Mod;h2=1ll*n/g*inv(n/g,m/g)%Mod; 
	rep(i,0,n-1)rd(a[i]);
	rep(i,0,m-1)rd(b[i]);
	rep(i,0,g-1){
		int pre=cnt;
		for(int j=i;j<n;j+=g){
			int t;
			if(vis[a[j]]>pre)t=vis[a[j]];
			else{
				t=vis[a[j]]=++cnt;mod[cnt]=i;
			}
			A[t].push_back(j/g);
		}
		for(int j=i;j<m;j+=g){
			int t;
			if(vis[b[j]]>pre)t=vis[b[j]];
			else{
				t=vis[b[j]]=++cnt;mod[cnt]=i;
			}
			B[t].push_back(j/g);
		}
	}
	ll All=0;
	rep(i,1,cnt)init(i),H[i]=gao(i,Mod-1),All+=1ll*A[i].size()*B[i].size();
	ll T=1ll*n*m/g;All=T-All;
	ll l=(K-1)/All*T,r=(K+All-1)/All*T-1;
	while(l<r){
		ll mid=(l+r)>>1;
		if(calc(mid)>=K)r=mid;
		else l=mid+1; 
	}
	printf("%lld ",r+1);
	return 0;
}