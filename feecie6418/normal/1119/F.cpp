#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
struct Heap { // K 
	multiset<ll> s1,s2;
	int K=0,cntneg=0;
	ll sum=0,sumneg=0;
	void Do() {
		while(s1.size()>K) {
			ll u=*--s1.end();
			s1.erase(s1.find(u)),s2.insert(u),sum-=u;
		}
		while(s1.size()<K&&s2.size()) {
			ll u=*s2.begin();
			s2.erase(s2.find(u)),s1.insert(u),sum+=u;
		}
	}
	void Ins(ll x) {
		s1.insert(x),sum+=x,Do();
		if(x<0)sumneg+=x,cntneg++;
	}
	void Del(ll x) {
		if(s1.find(x)!=s1.end())s1.erase(s1.find(x)),sum-=x;
		else if(s2.find(x)!=s2.end())s2.erase(s2.find(x));
		else assert(0);
		if(x<0)sumneg-=x,cntneg--;
		Do();
	}
	void MakeK(int k) {
		K=k,Do();
	}
	ll Query() {
		if(cntneg>=K)return sumneg;
		if(s1.size()<K)return 1e12;
		return sum;
	}
} q[250005];
struct E {
	int to,val;
};
int n,vst[250005],CUR;
ll f[250005][2];
vector<int> nd[250005];
vector<E> g[250005];
void dfs(int x,int fa,int fv) {
	vst[x]=1;
	ll sum=0;
	int cnt=g[x].size()-(bool)fa;
	for(E i:g[x]) {
		int y=i.to;
		if(y==fa)continue;
		if(g[y].size()<=CUR)break;
		dfs(y,x,i.val),sum+=f[y][1],q[x].Del(i.val),q[x].Ins(f[y][0]-f[y][1]+i.val);
	}
	if(fa)q[x].Del(fv);
	//cout<<x<<' '<<f[x][0]<<' '<<f[x][1]<<' '<<q[x].Query()<<'\n';
	q[x].MakeK(cnt-CUR),f[x][0]=sum+q[x].Query();
	q[x].MakeK(cnt-CUR+1),f[x][1]=sum+q[x].Query();
	f[x][0]=min(f[x][0],f[x][1]);
	if(fa)q[x].Ins(fv);
	for(E i:g[x]) {
		int y=i.to;
		if(y==fa)continue;
		if(g[y].size()<=CUR)break;
		q[x].Ins(i.val),q[x].Del(f[y][0]-f[y][1]+i.val);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1,x,y,z; i<n; i++) {
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	for(int j=1; j<=n; j++) {
		for(int i=0; i<g[j].size(); i++)nd[i].push_back(j);
	}
	for(int i=1; i<=n; i++) {
		sort(g[i].begin(),g[i].end(),[](E x,E y) {
			return g[x.to].size()>g[y.to].size();
		});
		for(E j:g[i])q[i].Ins(j.val);
	}
	for(int j=0; j<n; j++) {
		CUR=j;
		ll ans=0;
		for(int i:nd[j]) {
			if(vst[i])continue;
			dfs(i,0,0),ans+=f[i][0];
		}
		cout<<ans<<' ';
		for(int i:nd[j])vst[i]=0;
	}
}