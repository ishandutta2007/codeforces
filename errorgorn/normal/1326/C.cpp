
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

const int MOD=998244353;

int n,k;
int arr[200005];
vector<int> pos;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n>>k;
	for (int x=1;x<=n;x++){
		cin>>arr[x];
		if (arr[x]>n-k) pos.push_back(x);
	}
	
	
	ll ans=0;
	for (int x=n;x>n-k;x--) ans+=x;
	cout<<ans<<" ";
	
	sort(pos.begin(),pos.end());
	
	ans=1;
	
	for (int x=0;x<pos.size()-1;x++){
		ans=(ans*(pos[x+1]-pos[x]))%MOD;
	}
	
	cout<<ans<<endl;
}