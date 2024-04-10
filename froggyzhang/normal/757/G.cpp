#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
#define N 200020
int A,n,m,p,h[N],rt,now,maxsz[N],sz[N],vis[N],id[N],c[N];
long long ans;
struct line{
	int to,ne,v;
}a[N<<1];
inline void add(int x,int y,int z){
	a[++p].to=y;
	a[p].ne=h[x];
	a[p].v=z;
	h[x]=p;
}
void findrt(int x,int fa,int tot){
	sz[x]=1;
	maxsz[x]=0;
	for(int i=h[x];i;i=a[i].ne){
		if(vis[a[i].to]||a[i].to==fa)continue;
		findrt(a[i].to,x,tot);
		sz[x]+=sz[a[i].to];
		maxsz[x]=max(maxsz[x],sz[a[i].to]);
	}
	maxsz[x]=max(maxsz[x],tot-sz[x]);
	if(maxsz[x]<maxsz[now])now=x;
}
vector<int>f[N];
vector<long long>d[N];
vector<pair<int,long long> >tot1[N],tot2[N];
vector<pair<int,int> >Size[N];
pair<int,long long>g[N];
pair<int,int>gg[N];
void work(int x,int fa,int rt){
	Size[rt].push_back(mp(id[x],1));
	sz[x]=1;
	for(int i=h[x];i;i=a[i].ne)	{
		if(vis[a[i].to]||a[i].to==fa)continue;
		work(a[i].to,x,rt);
		sz[x]+=sz[a[i].to];
	}
}
void gx(int x,int fa,int now,int rt,long long dep){
	d[x].push_back(dep);
	f[x].push_back(rt);
	tot2[now].push_back(mp(id[x],dep));
	tot1[rt].push_back(mp(id[x],dep));
	for(int i=h[x];i;i=a[i].ne){
		if(vis[a[i].to]||a[i].to==fa)continue;
		gx(a[i].to,x,now,rt,dep+a[i].v);
	}
}
bool cmp(int a,int b){
	return Size[now][a].first<Size[now][b].first;
}
void dfs(int x){
	vis[x]=1;
	work(x,0,x);
	f[x].push_back(x);
	d[x].push_back(0);
	int z[Size[x].size()];
	for(int i=0;i<Size[x].size();i++)z[i]=i;
	memcpy (gg, &Size[x][0], sizeof (Size[x][0]) * Size[x].size());
	sort(z,z+Size[x].size(),cmp);
	for(int i=0;i<Size[x].size();i++)Size[x][i]=gg[z[i]];
	for(int i=1;i<Size[x].size();i++)Size[x][i].second+=Size[x][i-1].second;
	tot1[x].push_back(mp(id[x],0));
	for(int i=h[x];i;i=a[i].ne){
		if(vis[a[i].to])continue;
		now=0;
		findrt(a[i].to,x,sz[a[i].to]);
		gx(a[i].to,x,now,x,a[i].v);
		sort(tot2[now].begin(),tot2[now].end());
		for(int j=1;j<tot2[now].size();j++)tot2[now][j].second+=tot2[now][j-1].second;
		dfs(now);
	}
	memcpy (g, &tot1[x][0], sizeof (tot1[x][0]) * tot1[x].size());
	for(int i=0;i<Size[x].size();i++)tot1[x][i]=g[z[i]];
	for(int i=1;i<tot1[x].size();i++)tot1[x][i].second+=tot1[x][i-1].second;
}
inline int erfen(const vector<pair<int,long long> > &x,int k){
	if(x[x.size()-1].first<=k)return x.size();
	int l=0,r=x.size()-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(x[mid].first>k)r=mid;
		else l=mid+1;
	}
	return l;
}
inline long long ask(const vector<pair<int,long long> >&x,int l,int r){
	int fr=erfen(x,r),fl=erfen(x,l-1);
	if(!fr)return 0;
	fr--;
	if(!fl)return x[fr].second;
	fl--;
	return x[fr].second-x[fl].second;
}
inline long long ask(const vector<pair<int,long long> >&x,const vector<pair<int,int> >&y,int l,int r,long long k){
	int fr=erfen(x,r),fl=erfen(x,l-1);
	if(!fr)return 0;
	fr--;
	if(!fl)return x[fr].second+k*y[fr].second;
	fl--;
	return x[fr].second-x[fl].second+k*(y[fr].second-y[fl].second);
}
inline long long ask(int x,int l,int r){
	long long ans=ask(tot1[x],l,r);
	for(int i=f[x].size()-2;~i;i--){
		ans+=ask(tot1[f[x][i]],Size[f[x][i]],l,r,d[x][i]);
		ans-=ask(tot2[f[x][i+1]],Size[f[x][i+1]],l,r,d[x][i]);
	}
	return ans;
}
void update(int x,int y){
	int fx,fy;
	for(int i=f[y].size()-1;~i;i--){
		fy=erfen(tot1[f[y][i]],id[y]);
		fy-=2;
		if((~fy)&&tot1[f[y][i]][fy].first==id[x])break;
		fy++;
		tot1[f[y][i]][fy].first--,Size[f[y][i]][fy].first--;
	}
	for(int i=f[y].size()-1;i;i--){
		fy=erfen(tot2[f[y][i]],id[y]);
		fy-=2;
		if((~fy)&&tot2[f[y][i]][fy].first==id[x])break;
		fy++;
		tot2[f[y][i]][fy].first--;
	}
	for(int i=f[x].size()-1;~i;i--){
		fx=erfen(tot1[f[x][i]],id[x]);
		if((fx^tot1[f[x][i]].size())&&tot1[f[x][i]][fx].first==id[y]){
			tot1[f[x][i]][fx-1].second=tot1[f[x][i]][fx].second-d[x][i];
		}
		else{
			fx--;
			tot1[f[x][i]][fx].first++,Size[f[x][i]][fx].first++;
		}
	}
	for(int i=f[x].size()-1;i;--i){
		fx=erfen(tot2[f[x][i]],id[x]);
		if((fx^tot1[f[x][i]].size())&&tot2[f[x][i]][fx].first==id[y]){
			tot2[f[x][i]][fx-1].second=tot2[f[x][i]][fx].second-d[x][i-1];
		}
		else{
			fx--;
			tot2[f[x][i]][fx].first++;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		id[c[i]]=i;
	}
	for(int i=1;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	maxsz[0]=1e9+10;
	findrt(1,0,n);
	rt=now;
	dfs(now);
	while(m--){
		int opt,x,y,z;
		cin>>opt;
		if(opt==1){
			cin>>x>>y>>z;
			x^=ans;
			y^=ans;
			z^=ans;
			ans=ask(z,x,y);
			cout<<ans<<'\n';
			ans&=(1<<30)-1;
		}
		else{
			cin>>x;
			x^=ans;
			update(c[x],c[x+1]);
			id[c[x]]++;
			id[c[x+1]]--;
			swap(c[x],c[x+1]);
		}
	}
	return 0;
}