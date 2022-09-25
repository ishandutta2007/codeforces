#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,k,del[N],a[N],p[N],ans[N];
set<int> S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]]=i;
		S.insert(i);
	}
	for(int i=n,t=0;i>=1;--i){
		int u=p[i];
		if(!S.count(u))continue;
		ans[u]=t;
		S.erase(u);
		for(int j=0;j<k;++j){
			auto it=S.lower_bound(u);
			if(it==S.end())break;
			ans[*it]=t;
			S.erase(it);
		}
		for(int j=0;j<k;++j){
			auto it=S.lower_bound(u);
			if(it==S.begin())break;
			ans[*prev(it)]=t;
			S.erase(prev(it));	
		}
		t^=1;
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]+1;
	}
	return 0;
}