#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[1501][1501],b[1501][1501],f[1501][1501];
int ban[1501];
bool die[1501];
vector<int>ans;
vector<int>fun[1501];
int ord[1501];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
		}
		ord[i]=i;
	}
	
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> b[i][j];
			if(i!=1){
				f[i-1][j]=b[i-1][j]>b[i][j];
				ban[j]+=f[i-1][j];
			}
		}
	}
	stack<int>s;
	for(int i=1; i<=m ;i++){
		if(ban[i]==0) s.push(i);
	}
	while(!s.empty()){
		int x=s.top();s.pop();
		ans.push_back(x);
		for(int i=1; i<n ;i++){
			if(die[i]) continue;
			if(b[i][x]<b[i+1][x]){
				die[i]=true;
				for(int j=1; j<=m ;j++){
					if(ban[j]==0) continue;
					ban[j]-=f[i][j];
					if(ban[j]==0) s.push(j);
				}
			}
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto c:ans){
		for(int j=1; j<=n ;j++){
			fun[a[ord[j]][c]].push_back(ord[j]);
		}
		int ptr=0;
		for(int j=1; j<=n ;j++){
			for(auto c:fun[j]){
				ord[++ptr]=c;
			}
			fun[j].clear();
		}
	}
	bool ok=true;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(a[ord[i]][j]!=b[i][j]) ok=false;
		}
	}
	if(ok){
		cout << ans.size() << '\n';
		for(auto c:ans) cout << c << ' ';
		cout << '\n';
	}
	else cout << "-1\n";
}