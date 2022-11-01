#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(c) c.begin(),c.end()
ll root(ll a,ll arr[]){
	if(arr[a]==a){
		return a;
	}
	else {
	    arr[a] = root(arr[a],arr);
		return arr[a];
	}
}
void merg(ll a,ll b,ll arr[],ll size[]){
	a = root(a,arr);
	b = root(b,arr);
	if(a==b){
		return;
	}
	else{
		arr[b] = arr[a];
		size[a] += size[b];
	}
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 	ll n,m;
 	cin>>n>>m;
 	ll arr[n+1];
 	ll size[n+1];
 	for(ll i = 1;i<=n;i++){
 		arr[i] = i;
 		size[i] = 1;
 	}
 	vector<ll > p[n];
 	for(ll i = 0;i<m;i++){
 		ll k;
 		cin>>k;
 		if(k==0){
 			continue;
 		}
 		else {
 			ll t;
 			cin>>t;
 			while(k-1){
 				ll s;
 				cin>>s;
 				merg(t,s,arr,size);
 				k--;
 			}
 		}
 	}
 	for(ll i = 1;i<=n;i++){
 		cout<<size[root(i,arr)]<<" ";
 	}
 	clock_t time_p=clock();
	time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
 	
	return 0;
}