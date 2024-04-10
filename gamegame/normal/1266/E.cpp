#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll w[200001];
map<pair<ll,ll>,ll >mp;
ll sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> w[i];sum+=w[i];
	}
	cin >> q;
	for(int i=1; i<=q ;i++){
		ll s,t,u;cin >> s >> t >> u;
		if(mp[{s,t}]!=0){
			ll cur=w[mp[{s,t}]]++;
			mp[{s,t}]=0;
			if(cur>=0) sum++; 
		}
		if(u!=0){
			mp[{s,t}]=u;
			ll cur=w[u]--;
			if(cur>0) sum--; 
		}
		cout << sum << '\n';
	}
}