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
		
		sort(arr,arr+n);
		
		int l=(n-1)/2,r=n/2;
		while (l>=0){
			if (l!=r) cout<<arr[l]<<" "<<arr[r]<<" ";
			else cout<<arr[l]<<" ";
			
			l--;
			r++;
		}
		cout<<endl;
	}
}