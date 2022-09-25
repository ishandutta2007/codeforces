#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
int n;
pii ans[N];
struct Dish{
	int x,y,m,w,id;	
}a[N];
int calc(int l,int r){
	vector<pair<pii,Dish> > V;
	for(int i=l;i<=r;++i){
		V.emplace_back(pii(max(0,a[i].x-a[i].m),a[i].x-max(0,a[i].m-a[i].y)),a[i]);	
	}	
	sort(V.begin(),V.end(),[&](pair<pii,Dish> a,pair<pii,Dish> b){return a.first.second<b.first.second;});
	int tot=0,pos=-233;
	for(auto [Range,d]:V){
		auto [l,r]=Range;
		if(l>pos)pos=r,++tot;
		ans[d.id]=make_pair(d.x-pos,d.m-d.x+pos);	
	}
	return tot;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>a[i].m;
		a[i].w=a[i].x+a[i].y-a[i].m;
		a[i].id=i;
	}
	sort(a+1,a+n+1,[&](Dish &a,Dish &b){return a.w<b.w;});
	int Ans=0;
	for(int i=1,j=0;i<=n;++i){
		if(i==n||a[i+1].w^a[i].w){
			Ans+=calc(j+1,i);
			j=i;
		}
	}
	cout<<Ans<<'\n';
	for(int i=1;i<=n;++i){
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}