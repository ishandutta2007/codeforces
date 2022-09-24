#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[300005],m,isfir[300005];
vector<int> t[300005];
set<pr> s;
ll ans=0;
struct Thing{
	pr id;
	int w;
};
bool operator <(const Thing x,const Thing y){
	return x.w<y.w;
}
void Calc(int xx,int yy){
	//cout<<xx<<' '<<yy<<' '<<t[xx].back()<<' '<<t[yy].back()<<'\n';
	set<pr> f;
	priority_queue<Thing> q;
	q.push((Thing){pr((int)t[xx].size()-1,(int)t[yy].size()-1),t[xx].back()+t[yy].back()});
	f.insert(pr((int)t[xx].size()-1,(int)t[yy].size()-1));
	while(!q.empty()){
		Thing x=q.top();
		q.pop();
		pr ii=pr(t[xx][x.id.first],t[yy][x.id.second]);
		pr oo=x.id;
		if(ii.first!=ii.second&&!s.count(ii)){
			//cout<<ii.first<<' '<<ii.second<<' '<<x.w<<'\n';
			ans=max(ans,1ll*x.w*(xx+yy));
			return ;
		}
		if(oo.first){
			int u=oo.first-1,v=oo.second;
			if(f.count(pr(u,v)));else {
			f.insert(pr(u,v));
			q.push({pr(u,v),t[xx][u]+t[yy][v]});}
		}
		if(oo.second){
			int u=oo.first,v=oo.second-1;
			if(f.count(pr(u,v)));else {
			f.insert(pr(u,v));
			q.push({pr(u,v),t[xx][u]+t[yy][v]});}
		}
	}
}
void Solve(){
	scanf("%d%d",&n,&m);
	map<int,int> cnt;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),cnt[a[i]]++;
		if(cnt[a[i]]==1)isfir[i]=1;
	}
	for(int i=1;i<=n;i++)if(isfir[i])t[cnt[a[i]]].push_back(a[i]);
	vector<int> u;
	for(int i=1;i<=n;i++)if(t[i].size())u.push_back(i),sort(t[i].begin(),t[i].end());
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),s.insert(pr(x,y)),s.insert(pr(y,x));
	for(int i:u)for(int j:u)if(i<=j)Calc(i,j);
	cout<<ans<<'\n';
	ans=0;
	for(int i=1;i<=n;i++){
		a[i]=isfir[i]=0;
		t[i].clear();
	}
	s.clear();
}
int main(){
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}