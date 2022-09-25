#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n,k;
int arr[100005];
int ans[100005];

void rage(){
	cout<<"-1";
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
		
	cin>>n>>k;
	for (int x=0;x<k;x++) cin>>arr[x];
	
	for (int x=0;x<k;x++) ans[x]=x;
	
	for (int x=0;x<k;x++) if (arr[x]+ans[x]>n) rage();
	ans[k]=n;
	
	for (int x=k-1;~x;x--){
		if (arr[x]+ans[x]<ans[x+1]) ans[x]=ans[x+1]-arr[x];
	}
	
	if (ans[0]!=0) rage();
	
	for (int x=0;x<k;x++) cout<<ans[x]+1<<" ";
	
	
}