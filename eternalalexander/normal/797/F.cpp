#include <bits/stdc++.h>
#define maxn 5005
#define ll long long
#define int long long
#define pii std::pair<int,int>
const ll inf=6e9;
int n,m,x[maxn],p[maxn],v[maxn],c[maxn],rank[maxn];
std::priority_queue<pii,std::vector<pii>,std::greater<pii> >q0,q1;
ll ans=0;
int cmp(int a,int b){return p[a]<p[b];}

void insert_mouse(int x){
	int v,d;
	std::tie(v,d)=q1.top();q1.pop();
	ans+=v+x;
	q0.emplace(-2*x-v,1);
	if (--d)q1.emplace(v,d);
}

void insert_hole(int x,int c){

	int f=0,v,d;
	while(!q0.empty()&&f<c&&q0.top().first+x<0){
		std::tie(v,d)=q0.top();q0.pop();
		int fl=std::min(c-f,d);
		ans+=(ll)(v+x)*fl;f+=fl;
		if(d-=fl)q0.emplace(v,d);
		q1.emplace(-2*x-v,fl);
	}if(f<c)q1.emplace(-x,c-f);
	if(f)q0.emplace(-x,f);
}
		

signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
	for(int i=1;i<=m;++i)scanf("%lld%lld",&p[i],&c[i]),rank[i]=i;
	std::sort(x+1,x+n+1);
	std::sort(rank+1,rank+m+1,cmp);
	if(std::accumulate(c+1,c+m+1,0)<n)return puts("-1");
	insert_hole(-inf,n);
	for(int i=1,j=1;i<=n||j<=m;j>m||(i<=n&&x[i]<=p[rank[j]])?(insert_mouse(x[i]),i++):(insert_hole(p[rank[j]],c[rank[j]]),j++));
	printf("%lld",ans);
	return 0;
}