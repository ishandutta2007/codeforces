#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=505;
ll n,m;
char c[N][N];
char ans[N][N];
bool spc[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
			ans[i][j]='.';
		}
		spc[i]=false;
	}
	if(m==1){
		for(int i=1; i<=n ;i++) cout << "X\n";
		return;
	}
	int st=2;
	if(n%3==1) st=1;
	while(st<=n){
		spc[st]=true;
		st+=3;
	}
	for(int i=1; i<=n ;i++){
		if(!spc[i]) continue;
		for(int j=1; j<=m ;j++) ans[i][j]='X';
		if(i<=3) continue;
		if(c[i-1][2]=='X' || c[i-2][2]=='X') ans[i-1][2]=ans[i-2][2]='X';
		else c[i-1][1]=c[i-2][1]='X'; 
	}
	for(int i=1; i<=n ;i++){
		if(spc[i]) continue;
		for(int j=1; j<=m ;j++){
			if(c[i][j]=='X') ans[i][j]='X';
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}