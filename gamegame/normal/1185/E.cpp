#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x1[27],x2[27],y1[27],y2[27];
int n,m;
char c[2001][2001],d[2001][2001];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=26 ;i++) x1[i]=x2[i]=y1[i]=y2[i]=0;
	int mc=0;
	for(int i=1; i<=n ;i++)
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];d[i][j]='.';
			if(c[i][j]=='.') continue;
			int cl=c[i][j]-'a'+1;
			mc=max(mc,cl);
			if(x1[cl]==0) x1[cl]=i,y1[cl]=j;
			x2[cl]=i,y2[cl]=j;
		}
	if(mc==0){
		cout << "YES\n0\n";
		return;
	}
	int clr=0;
	for(int i=1; i<=mc ;i++){
		if(x1[i]==0){
			x1[i]=x2[i]=x1[mc],y1[i]=y2[i]=y1[mc];
		}
		if(x1[i]!=x2[i] && y1[i]!=y2[i]){
			cout << "NO\n";return;
		}
		for(int j=x1[i]; j<=x2[i] ;j++){
			for(int k=y1[i]; k<=y2[i] ;k++){
				d[j][k]='a'+i-1;
			}
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(c[i][j]!=d[i][j]){
				cout << "NO\n";return;
			}
		}
	}
	cout << "YES\n";cout << mc << '\n';
	for(int i=1; i<=26 ;i++){
		if(x1[i]==0) break;
		cout << x1[i] << ' ' << y1[i] << ' ' << x2[i] << ' ' << y2[i] << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}