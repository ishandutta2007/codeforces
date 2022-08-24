#include<bits/stdc++.h>
using namespace std;
char c[61][61];
bool e[61][61];
int n,m;
bool checksame(){
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(c[i][j]!=c[1][1]) return false;
		}
	}
	if(c[1][1]=='A') cout << "0\n";
	else cout << "MORTAL\n";
	return true;
}
bool check1(){
	bool ok1=true,ok2=true,ok3=true,ok4=true;
	for(int i=1; i<=n ;i++){
		if(c[i][1]!='A') ok1=false;
		if(c[i][m]!='A') ok2=false;
	}
	for(int i=1; i<=m ;i++){
		if(c[1][i]!='A') ok3=false;
		if(c[n][i]!='A') ok4=false;
	}
	if(ok1 || ok2 || ok3 || ok4){
		cout << "1\n";return true;
	}
	return false;
}
bool check2a(){
	bool ok=(c[1][1]=='A') || (c[1][m]=='A') || (c[n][1]=='A') || (c[n][m]=='A');
	if(ok){
		cout << "2\n";return true;
	}
	return false;
}
bool check2b(){
	for(int i=1; i<=n ;i++){
		bool ok=true;
		for(int j=1; j<=m ;j++){
			if(c[i][j]!='A') ok=false;
		}
		if(!ok) continue;
		cout << "2\n";
		return true;
	}
	for(int i=1; i<=m ;i++){
		bool ok=true;
		for(int j=1; j<=n ;j++){
			if(c[j][i]!='A') ok=false;
		}
		if(!ok) continue;
		cout << "2\n";
		return true;
	}
	return false;
}
bool check3(){
	bool ok=false;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(e[i][j] && c[i][j]=='A') ok=true;
		}
	}
	if(ok){
		cout << "3\n";return true;
	}
	return false;
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
			e[i][j]=false;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(i==1 || i==n || j==1 || j==m) e[i][j]=true;
		}
	}
	if(checksame()) return;
	if(check1()) return;
	if(check2a()) return;
	if(check2b()) return;
	if(check3()) return;
	cout << "4\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();	
}