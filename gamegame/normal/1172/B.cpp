#include<bits/stdc++.h>
using namespace std;
int n,m;
int in[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;in[u]++;in[v]++;
	}
	long long ans=1;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=in[i] ;j++) ans=ans*j%998244353;
	}
	cout << ans*n%998244353 << endl;
}