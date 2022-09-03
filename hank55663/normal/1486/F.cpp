#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int p[300005][20];
int d[300005];
vector<int> v[300005];
vector<pii> query[300005];
void dfs(int x,int f){
	d[x]=d[f]+1;
	p[x][0]=f;
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x);
		}
	}
}
void build(int n){
	for(int i = 1;i<20;i++){
		for(int j = 1;j<=n;j++){
			p[j][i]=p[p[j][i-1]][i-1];
		}
	}
}
int lca(int x,int y){
	if(d[x]>d[y])swap(x,y);
	int dd=d[y]-d[x];
	for(int i = 0;i<20;i++){
		if(dd&(1<<i))y=p[y][i];
	}
	if(x==y)return x;
	for(int i = 19;i>=0;i--){
		if(p[x][i]!=p[y][i]){
			x=p[x][i];
			y=p[y][i];
		}
	}
	return p[x][0];
}
LL ans=0;
bool cmp(const pii &p,const pii &q){
	return p.y<q.y;
}
set<pii> dfs2(int x,int f){
	vector<pii> vv;
	set<pii> s;
	LL tmpans=0;
	for(auto it:v[x]){
		if(it!=f){
			set<pii> s2=dfs2(it,x);
			int tot=0;
			while(s2.size()&&s2.rbegin()->x==d[x]){
				vv.pb(mp(s2.rbegin()->y,it));
				//printf("%d %d\n",s2.begin()->x,s2.begin()->y);
				s2.erase(*s2.rbegin());
				//if(s2.size()){
				//	printf("%d %d\n",s2.begin()->x,s2.begin()->y);
				//}
				tot++;
			}
			tmpans-=tot*1ll*s2.size();
			//printf("%d %d\n",tot,s2.size());
			if(s2.size()>s.size())swap(s2,s);
			for(auto it:s2){
				s.insert(it);
			}
		}
	}
	//printf("?%d %lld %lld\n",x,ans,tmpans);
	ans+=tmpans;
	for(auto it:query[x]){
		if(it.x==d[x])vv.pb(mp(it.y,0));
		else s.insert(it);
	}
	//for(auto it:s)printf("%d %d\n",it.x,it.y);
	//printf("%d %d\n",vv.size(),s.size());
	if(vv.size()){
	ans+=vv.size()/2ll*s.size();
	sort(vv.begin(),vv.end());
	vector<pii> tmp;
	vector<int> tmp2;
	int tot=0;
	int add=0;
	for(int i = 0;i<vv.size();i+=2){
		if(vv[i].y==0&&vv[i+1].y==0){
			ans+=vv.size()/2-1;
			tot++;
		}
		else{
		    add++;
			if(vv[i].y==0);//tmp.pb(mp(vv[i+1].y,vv[i+1].y));
			else tmp.pb(mp(vv[i].y,vv[i+1].y));
			if(vv[i].y)tmp2.pb(vv[i].y);
			tmp2.pb(vv[i+1].y);
		}
	}
	ans-=(tot)*1ll*(tot-1)/2;
	//printf("%d\n",ans);
	ans+=add*1ll*(add-1)/2;
	//	printf("%d\n",ans);
	sort(tmp.begin(),tmp.end());
	sort(tmp2.begin(),tmp2.end());
	int cnt=0;
	int xx=0;
	for(auto it:tmp2){
		if(xx!=it){
			ans-=cnt*1ll*(cnt-1)/2;
			cnt=1;
			xx=it;
		
		}
		else{
			cnt++;
		}
	}
	ans-=cnt*1ll*(cnt-1)/2;
	cnt=0;
	pii p=mp(0,0);
	for(auto it:tmp){
		if(it==p)cnt++;
		else{
			ans+=cnt*1ll*(cnt-1)/2;
			p=it;
			cnt=1;
		}
	}
	ans+=cnt*1ll*(cnt-1)/2;
	}
	//	printf("?%d %lld\n",x,ans);
	return s;
}
bool solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	build(n);
	int q;
	scanf("%d",&q);
	for(int i = 0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int aa=lca(a,b);
		//printf("%d\n",aa);
		query[a].pb(mp(d[aa],i));
		query[b].pb(mp(d[aa],i));
	}
	dfs2(1,0);
	printf("%lld\n",ans);
	return true;
}
int main(){
	int t=1;//000000;
    //scanf("%d",&t);
    while(t--)solve();
}