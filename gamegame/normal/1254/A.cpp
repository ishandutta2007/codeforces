#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
char c[101][101];
char ans[101][101];
string s;
void solve(){
	s="";
	for(char i='0'; i<='9' ;i++) s+=i;
	for(char i='A'; i<='Z' ;i++) s+=i;
	for(char i='a'; i<='z' ;i++) s+=i;
	int n,m,k;
	cin >> n >> m >> k;
	vector<pair<int,int> >v;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
			cnt+=c[i][j]=='R';
		}
	}
	for(int i=1; i<=n ;i++){
		if(i%2==1){
			for(int j=1; j<=m ;j++) v.push_back({i,j});
			
		}
		else{
			for(int j=m; j>=1 ;j--) v.push_back({i,j});
		}
	}
	vector<int>u;
	for(int i=1; i<=cnt%k ;i++){
		u.push_back(cnt/k+1);
	}
	for(int i=cnt%k+1; i<=k ;i++){
		u.push_back(cnt/k);
	}
	while(u.size()>1){
		int life=u.back();
		u.pop_back();
		while(!v.empty() && life>0){
			ans[v.back().fi][v.back().se]=s.back();
			life-=(c[v.back().fi][v.back().se]=='R');
			v.pop_back();
		}
		s.pop_back();
	}
	while(!v.empty()){
		ans[v.back().fi][v.back().se]=s.back();
		v.pop_back();
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	for(char i='0'; i<='9' ;i++) s+=i;
	for(char i='A'; i<='Z' ;i++) s+=i;
	for(char i='a'; i<='z' ;i++) s+=i;
	int t;cin >> t;while(t--) solve();
}