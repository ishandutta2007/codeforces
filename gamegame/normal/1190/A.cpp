#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int m;
ll p[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=m ;i++){
		cin >> p[i];
	}
	int cur=1;
	int ans=0;
	while(cur<=m){
		ans++;
		ll duh=(p[cur]-cur)/k*k;
		int nw=cur;
		while(nw<=m && p[nw]-cur+1<=duh+k) nw++;
		cur=nw;
	}
	cout << ans << endl;
}