#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int prime[100005],vst[100005],miu[100005],a,b,c,d[100005],cnt,used[100005];
ll fa[100005],fb[100005],fc[100005];
struct Node{
	int to,val;
};
vector<Node> g[100005];
struct Tmp{
	int u,v,w;
}e[800005];
void Mobius(int n) {
	miu[1]=1;
	for(int i=2; i<=n; i++) {
		if(!vst[i]) {
			prime[++prime[0]]=i;
			miu[i]=-1;
		}
		for(int j=1; j<=prime[0]&&i*prime[j]<=n; j++) {
			vst[i*prime[j]]=1;
			if(i%prime[j])miu[i*prime[j]]=-miu[i];
			else {
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
}
void Solve(){
	cin>>a>>b>>c;
	int mx=max(max(a,b),c),mn=min(min(a,b),c);
	memset(fa,0,sizeof(fa)),memset(fb,0,sizeof(fb)),memset(fc,0,sizeof(fc));
	for(int i=1;i<=a;i++)for(int j=i;j<=a;j+=i)fa[i]+=a/j;
	for(int i=1;i<=b;i++)for(int j=i;j<=b;j+=i)fb[i]+=b/j;
	for(int i=1;i<=c;i++)for(int j=i;j<=c;j+=i)fc[i]+=c/j;
	ll ans=0;
	for(int i=1;i<=mn;i++)if(miu[i])ans+=miu[i]*miu[i]*miu[i]*fa[i]*fb[i]*fc[i];
	memset(d,0,sizeof(d)),cnt=0;
	for(int g=1;g<=mx;g++){
		for(int i=1;i*g<=mx;i++){
			if(!miu[i*g])continue;
			for(int j=i+1;1ll*i*j*g<=mx;j++){
				if(!miu[j*g]||__gcd(i,j)>1)continue;
				int u=i*g,v=j*g,lcm=i*j*g;
				ans+=miu[u]*miu[u]*miu[v]*(fa[u]*fb[lcm]*fc[lcm]+fb[u]*fa[lcm]*fc[lcm]+fc[u]*fa[lcm]*fb[lcm]);
				ans+=miu[u]*miu[v]*miu[v]*(fa[v]*fb[lcm]*fc[lcm]+fb[v]*fa[lcm]*fc[lcm]+fc[v]*fa[lcm]*fb[lcm]);
				d[u]++,d[v]++,e[++cnt]={u,v,lcm};
			} 
		}
	}
	for(int i=1;i<=mx;i++)g[i].clear();
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(d[u]>d[v]||(d[u]==d[v]&&u>v))g[u].push_back({v,w});
		else g[v].push_back({u,w});
	}
	for(int x=1;x<=mx;x++){
		if(!miu[x])continue;
		for(Node t:g[x])used[t.to]=t.val;
		for(Node t:g[x]){
			int y=t.to,xy=t.val;
			if(!miu[y])continue;
			for(Node tt:g[y]){
				int z=tt.to;
				if(!used[z])continue;
				int yz=tt.val,xz=used[z];
				ans+=miu[x]*miu[y]*miu[z]*(fa[xy]*fb[xz]*fc[yz]+fa[xy]*fb[yz]*fc[xz]+fa[xz]*fb[yz]*fc[xy]+
				fa[xz]*fb[xy]*fc[yz]+fa[yz]*fb[xz]*fc[xy]+fa[yz]*fb[xy]*fc[xz]);
			}
		}
		for(Node t:g[x])used[t.to]=0;
	}
	cout<<ans%1073741824<<endl;
}
int main() {
	Mobius(100000);
	int T=1;
	while(T--)Solve();
}