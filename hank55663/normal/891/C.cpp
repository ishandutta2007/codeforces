#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int f[500005];
vector<pii> vv;
int Find(int a){
	if(f[a]==a)
	return a;
	return f[a]=Find(f[a]);
}
int Find2(int a){
	if(f[a]==a)
	return a;
	int x=f[a];
	f[a]=Find2(f[a]);
	vv.pb(mp(a,x));
	return f[a];
}
void recover(){
	for(auto it=vv.rbegin();it!=vv.rend();it++){
		f[it->x]=it->y;
	}
	vv.clear();
}
struct road{
	int u,v,w,i;
};
map<int,vector<pair<int,vector<road> > > > ma;
int ans[500005];
road r[500005];
bool operator<(const road &a,const road &b){
	return a.w<b.w;
}
void go(int w){
	vector<pair<int,vector<road> > > v=ma[w];
	for(auto it=v.begin();it!=v.end();it++){
//		printf("%d %d\n",it->x,w);
		if(ans[it->x]==0)
		continue;
		for(auto it2=it->y.begin();it2!=it->y.end();it2++){
			int x=it2->u;
			int y=it2->v;
			int fx=Find2(x);
			int fy=Find2(y);
			if(fx==fy){
				ans[it->x]=0;
			}
			if(ans[it->x]==0)
			break;
			vv.pb(mp(fx,f[fx]));
			f[fx]=fy;
		}
		recover();
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		r[i]={u,v,w,i};
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		ans[i]=1;
		int k;
		scanf("%d",&k);
		map<int,vector<road> > mm;
		for(int j=0;j<k;j++){
			int a;
			scanf("%d",&a);
			mm[r[a].w].pb(r[a]);
		}
		for(auto it=mm.begin();it!=mm.end();it++){
			ma[it->x].pb(mp(i,it->y));
		}
	}
	r[0].w=0;
	sort(r+1,r+m+1);
	for(int i=1;i<=m;i++){
		if(r[i].w!=r[i-1].w)
		go(r[i].w);
		int a=r[i].u;
		int b=r[i].v;
		int fa=Find(a);
		int fb=Find(b);
		if(fa!=fb){
			f[fa]=fb;
		}
	}
	for(int i=1;i<=q;i++)
	printf("%s\n",ans[i]?"YES":"NO");
}