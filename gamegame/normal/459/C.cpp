#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,d;
ll g[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> d;
	for(int i=0; i<n ;i++){
		ll cur=i;
		for(int j=0; j<d ;j++){
			g[i][j]=cur%k;
			cur/=k;
		}
		if(cur>0){
			return cout << "-1\n",0;
		}
	}
	for(int i=0; i<d ;i++){
		for(int j=0; j<n ;j++){
			cout << g[j][i]+1 << ' ';
		}
		cout << '\n';
	}
}