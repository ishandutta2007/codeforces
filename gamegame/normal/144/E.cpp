#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e5+1;
int n,m;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >pq;
vector<pair<int,int> >v[N];
vector<int>ans;
ll x[N],y[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		cin >> x[i] >> y[i];
		x[i]=n+1-x[i];
		v[x[i]].push_back({y[i],i});
	}
	for(int i=1; i<=n ;i++){
		for(auto cur:v[i]) pq.push(cur);
		while(!pq.empty() && pq.top().fi<i) pq.pop();
	//	cout << pq.size() << endl;
		if(!pq.empty()){
			//cout << "hihi" << endl;
			ans.push_back(pq.top().se);
			pq.pop();
		}
	//	cout << pq.size() << endl;
	}
	cout << ans.size() << endl;
	sort(ans.begin(),ans.end());
	for(auto c:ans) cout << c << " ";
}