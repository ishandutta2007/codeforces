#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int B=150005;
int n,m,v1[310005],v2[310005],v3[310005],v4[310005],nxt[310005],isok[310005];
vector<int> g[310005],G1[310005],G2[310005];
void Clear(){
	for(int i=0;i<=310000;i++){
		g[i].clear(),G1[i].clear(),G2[i].clear(); 
		v1[i]=v2[i]=v3[i]=v4[i]=nxt[i]=isok[i]=0;
	}
}
void dfs1(int x,int v[]){
	v[x]=1;
	for(int y:G1[x])if(!v[y])dfs1(y,v);
}
void dfs2(int x,int v[]){
	v[x]=1;
	for(int y:G2[x])if(!v[y])dfs2(y,v);
}
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y),g[x].push_back(y);
		if(x+1==y)isok[x]=1;
	}
	for(int i=1;i<=n;i++)g[0].push_back(i),g[i].push_back(n+1);
	isok[0]=isok[n]=1,nxt[n+1]=n+1;
	for(int i=n;i>=0;i--){
		if(isok[i])nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	if(nxt[0]==n+1){
		cout<<1ll*n*(n-1)/2<<'\n';
		return Clear();
	}
	for(int i=0;i<=n;i++){
		for(int j:g[i]){
			if(j>i+1&&nxt[i+1]>=j-1){
				G1[i+1].push_back(j+B),G2[j+B].push_back(i+1);
				G1[i+B+1].push_back(j),G2[j].push_back(i+B+1);
			}
		}
	}
	int I=0;
	for(int i=0;i<=n;i++)if(nxt[i]==i){I=i;break;}
	dfs1(I+1,v1),dfs2(I+1,v2);
	dfs1(I+B+1,v3),dfs2(I+B+1,v4);
	ll ans=0,c1=0,c2=0;
	for(int i=1;i<=I+1;i++)if(nxt[0]>=i-1)c1+=v2[i];
	for(int i=I+1;i<=n+1;i++)if(nxt[i]>=n+1)c2+=v1[i];
	ans+=c1*c2,c1=c2=0;
	for(int i=1;i<=I+1;i++)if(nxt[0]>=i-1)c1+=v4[i];
	for(int i=I+1;i<=n+1;i++)if(nxt[i]>=n+1)c2+=v3[i];
	ans+=c1*c2,c1=c2=0;
	for(int i=1;i<=I+1;i++)if(nxt[0]>=i-1)c1+=v2[i]&&v4[i];
	for(int i=I+1;i<=n+1;i++)if(nxt[i]>=n+1)c2+=v1[i]&&v3[i];
	ans-=c1*c2;
	if(nxt[0]>=I&&nxt[I+1]>=n+1)ans--;
	cout<<ans<<'\n';
	Clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}