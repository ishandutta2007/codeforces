#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,m,Q,a[N][N];
map<int,int> L,R;
map<int,set<int> > mp;
ll ans;
void Init(int x,int t){
	if(!L.count(x)){
		L[x]=t-1,R[x]=t+1;	
	}
	else{
		L[x]=min(L[x],t-1);
		R[x]=max(R[x],t+1);
	}
}
int calc(int x){
	return x*(x+1)/2;	
}
void Del(int x,int t){
	auto it=mp[x].lower_bound(t);
	ans-=calc((*it)-(*prev(it))-1)+calc((*next(it))-(*it)-1);
	ans+=calc((*next(it))-(*prev(it))-1);
	mp[x].erase(t);	
}
void Ins(int x,int t){
	mp[x].insert(t);	
	auto it=mp[x].lower_bound(t);
	ans+=calc((*it)-(*prev(it))-1)+calc((*next(it))-(*it)-1);
	ans-=calc((*next(it))-(*prev(it))-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			Init(j-i,i+j);
			Init(j-i+1,i+j);	
		}
	}
	for(auto [x,t]:L)mp[x].insert(t);
	for(auto [x,t]:R)mp[x].insert(t),ans+=calc(t-L[x]-1);
	ans-=n*m;
	while(Q--){
		int x,y;
		cin>>x>>y;
		if(a[x][y]){
			Del(y-x,x+y);
			Del(y-x+1,x+y);
			--ans;
		}
		else{
			Ins(y-x,x+y);
			Ins(y-x+1,x+y);
			++ans;
		}
		a[x][y]^=1;
		cout<<ans<<'\n';
	}
	return 0;
}