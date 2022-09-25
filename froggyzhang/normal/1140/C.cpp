#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,k;
pair<int,int> a[N];
priority_queue<int,vector<int>,greater<int> > q;
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i].second>>a[i].first;
	}
	sort(a+1,a+n+1,greater<pair<int,int> >());
	ll ans=0,sum=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i){
		if(q.size()<k||a[i].second>q.top()){
			if(q.size()==k)sum-=q.top(),q.pop();
			q.push(a[i].second);
			sum+=a[i].second;
		}
		ans=max(ans,sum*a[i].first);	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;;
	while(T--)Solve();
	return 0;
}