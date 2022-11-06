#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11,M=1e6+11;
int c[M];
/*void add(int x,int v){
	assert(x);
	for(;x<M;x+=x&-x)c[x]+=v;
}
int qry(int x){
	int ret=0;
	for(;x;x-=x&-x)ret+=c[x];
	return ret;
}*/
int x[N],y[N];
int n,m,k;
struct P{
	int x,y;
} a[N],b[N];
int t1,t2;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>m>>k){
		for(int i=0;i<n;++i)cin>>x[i];
		for(int i=0;i<m;++i)cin>>y[i];
		t1=t2=0;
		for(int i=0;i<k;++i){
			int u,v;
			cin>>u>>v;
			int p=lower_bound(x,x+n,u)-x;
			int q=lower_bound(y,y+m,v)-y;
			if(x[p]==u&&y[q]==v)continue;

			if(x[p]==u){
				a[t1++]=(P){p,q};
				//cerr<<"t1 "<<u<<" "<<v<<endl;
			}
			else {
				assert(y[q]==v);
				b[t2++]=(P){p,q};
				//cerr<<"t2 "<<u<<" "<<v<<endl;
			}
		}
		sort(a,a+t1,[](P i,P j){return i.x<j.x;});
		sort(b,b+t2,[](P i,P j){return i.y<j.y;});
		long long ans=0;
		for(int i=0;i<t1;++i){
		//	cerr<<i<<" "<<a[i].x<<" "<<a[i].y<<endl;
			//add(a[i].y,1);
			++c[a[i].y];
		}
		for(int i=0,j;i<t1;i=j){
			for(j=i;j<t1&&a[j].x==a[i].x;++j){
				//add(a[j].y,-1);
				--c[a[j].y];
			}
			for(j=i;j<t1&&a[j].x==a[i].x;++j){
				//int q=lower_bound(y,y+m,a[j].y-1)-y;
				ans+=c[a[j].y];//qry(y[q])-qry(y[q-1]+1);
			}
		}
		//cerr<<"pre "<<ans<<endl;
	//	for(int i=0;i<M;++i)assert(!c[i]);
	//cerr<<"----\n";
		for(int i=0;i<t2;++i){
		//	cerr<<i<<" "<<b[i].x<<" "<<b[i].y<<endl;
			//add(b[i].x,1);
			++c[b[i].x];
		}
		for(int i=0,j;i<t2;i=j){
			for(j=i;j<t2&&b[j].y==b[i].y;++j){
				//add(b[j].x,-1);
				--c[b[j].x];
			}
			for(j=i;j<t2&&b[j].y==b[i].y;++j){
				//int p=lower_bound(x,x+n,b[j].x-1)-x;
				//cerr<<x[p]<<" "<<b[j].x<<endl;
				ans+=c[b[j].x];//qry(x[p])-qry(x[p-1]+1);
			}
		}
		cout<<ans<<"\n";
	}
}