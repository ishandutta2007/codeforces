#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		for (int x=0;x<n;x++) cin>>arr[x];
		
		int most=arr[0];
		int ans=0;
		
		for (int x=1;x<n;x++){
			most=max(most,arr[x]);
			
			if (most!=arr[x]) ans=max(ans,32-__builtin_clz(most-arr[x]));
		}
		
		cout<<ans<<endl;
	}
}