#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,m;
ll arr[1005];
int main(){
	cin>>n>>m;
	
	if (n>1002){
		cout<<"0"<<endl;
		return 0;
	}
	
	for (int x=0;x<n;x++){
		cin>>arr[x];
	}
	
	ll ans=1;
	
	for (int x=0;x<n;x++)
		for (int y=x+1;y<n;y++){
			ans*=abs(arr[x]-arr[y]);
			ans%=m;
		}
		
	cout<<ans;
}