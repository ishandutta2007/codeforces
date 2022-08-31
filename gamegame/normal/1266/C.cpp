#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	if(n==1 && m==1) return cout << "0\n",0;
	if(m==1){
		for(int i=1+m; i<=m+n ;i++){
		for(int j=1; j<=m ;j++){
				cout << i*j << ' ';
			}
			cout << '\n';
		}
		return 0;
	}
	for(int i=1; i<=n ;i++){
		for(int j=1+n; j<=m+n ;j++){
			cout << i*j << ' ';
		}
		cout << '\n';
	}
}