
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'


int n;
ll arr[200005];
ll best;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n;
	for (int x=1;x<=n;x++) cin>>arr[x];
	
	for (int x=1;x<=n;x++){
		arr[x]=best+arr[x];
		best=max(best,arr[x]);
	}
	
	for (int x=1;x<=n;x++) cout<<arr[x]<<" ";
	
}