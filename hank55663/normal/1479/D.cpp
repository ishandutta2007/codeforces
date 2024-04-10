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
vector<int> v[300005];
int a[300005];
int in[300005];
int out[300005];
int p[20][300005];
int d[300005];
vector<int> a2;
void dfs(int x,int f){
	in[x]=a2.size();
	a2.pb(a[x]);
	d[x]=d[f]+1;
	p[0][x]=f;
	for(auto it:v[x]){
		if(it!=f)
			dfs(it,x);
	}
	out[x]=a2.size();
	a2.pb(a[x]);
}
void build(int n){
	for(int i = 1;i<20;i++){
		for(int j = 1;j<=n;j++){
			p[i][j]=p[i-1][p[i-1][j]];
		}
	}
}
int qlca(int x,int y){
	if(d[x]>d[y])swap(x,y);
	int dd=d[y]-d[x];
	for(int i = 0;i<20;i++){
		if(dd&(1<<i)){
			y=p[i][y];
		}
	}
	if(x==y)return x;
	for(int i =19;i>=0;i--){
		if(p[i][y]!=p[i][x]){
			x=p[i][x];
			y=p[i][y];
		}
	}
	return p[0][x];
}
//int a[300005];
struct qq{
	int ql,qr,l,r,lca;
	qq(int a,int b,int c,int d,int e){
		ql=a;
		qr=b;
		l=c;
		r=d;
		lca=e;
	}
};
int Size=750;
bool cmp(const pair<qq,int> &p,const pair<qq,int> &q){
	if(p.x.ql/Size==q.x.ql/Size){
		return p.x.qr<q.x.qr;
	}
	else{
		return p.x.ql<q.x.ql;
	}
}
int cnt[300005];
int block[750];
void solve(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
	for(int i = 1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		//x=rand()%i+1;
      //  y=i+1;
        v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	build(n);
	vector<pair<qq,int> > qu;
	int ans[300005];
//	int uuu[100005],vvv[100005];
	for(int i= 0;i<q;i++){
		int u,v,l,r;
       // u=rand()%n+1;
      //  v=rand()%n+1;
      //  l=rand()%n+1;
     //   r=rand()%n+1;
      //  if(l>r)swap(l,r);
		scanf("%d %d %d %d",&u,&v,&l,&r);
		///uuu[i]=u;
	///	vvv[i]=v;
		if(u==v){
			if(a[u]>=l&&a[u]<=r)
			ans[i]=a[u];
			else
			ans[i]=-1;
			continue;
		}
		int lca=qlca(u,v);
		if(out[u]<in[v]){
			qu.pb(mp(qq(out[u],in[v],l,r,lca),i));
		}
		else if(out[v]<in[u]){
			qu.pb(mp(qq(out[v],in[u],l,r,lca),i));
		}
		else if(out[v]<out[u]){
			qu.pb(mp(qq(out[v],out[u]-1,l,r,lca),i));
		}
		else if(out[u]<out[v]){
			qu.pb(mp(qq(out[u],out[v]-1,l,r,lca),i));
		}
	}
	sort(qu.begin(),qu.end(),cmp);
	int l=0,r=-1;
    int tot=0;
   // return;
	for(auto it:qu){
		while(l>it.x.ql){
			l--;
			tot++;
            //block[a2[l]/Size]-=cnt[a2[l]];
            cnt[a2[l]]^=2;
            block[a2[l]/Size]+=cnt[a2[l]]-1;
		}
		while(r<it.x.qr){
			r++;
            //block[a2[r]/Size]-=cnt[a2[r]];
            cnt[a2[r]]^=2;
            block[a2[r]/Size]+=cnt[a2[r]]-1;
			tot++;
		}
		while(l<it.x.ql){
			tot++;
           // block[a2[l]/Size]-=cnt[a2[l]];
            cnt[a2[l]]^=2;
            block[a2[l]/Size]+=cnt[a2[l]]-1;
			l++;
		}
		while(r>it.x.qr){
			tot++;
            //block[a2[r]/Size]-=cnt[a2[r]];
            cnt[a2[r]]^=2;
            block[a2[r]/Size]+=cnt[a2[r]]-1;
			r--;
		}
      //  printf("%d\n",block[0]);
		ans[it.y]=-1;
		cnt[a[it.x.lca]]^=2;
		if(cnt[a[it.x.lca]]){
			block[a[it.x.lca]/Size]++;
		}
		else{
			block[a[it.x.lca]/Size]--;
		}
		//for(int i = it.x.ql;i<=it.x.qr;i++){
		//	printf("%d ",a2[i]);
		//}
       //  printf("%d\n",block[0]);
		//printf("q:%d %d?\n",it.y,it.x.lca);
		for(int i = it.x.l/Size;i<=it.x.r/Size;i++){
			if(block[i]){
				int ok=0;
				for(int j = i*Size;j<(i+1)*Size;j++){
					if(cnt[j]&&j>=it.x.l&&j<=it.x.r){
						ok=1;
						ans[it.y]=j;
						break;
					}
				}
				if(ok)break;
			}
		}
		cnt[a[it.x.lca]]^=2;
		if(cnt[a[it.x.lca]]){
			block[a[it.x.lca]/Size]++;
		}
		else{
			block[a[it.x.lca]/Size]--;
		}
	}
   // printf("%d\n",tot);
	for(int i = 0;i<q;i++)printf("%d\n",ans[i]);
}
int main(){
    int t=1;00000;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/