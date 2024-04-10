#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n,m;
int arr[2100000];
vector<int> ans;

void dfs(int i){
	if (arr[i]==-1) return;
	
	int curr;
	int val;
	while (true){
		curr=i;
		
		while (true){
			if (arr[curr*2]==-1 && arr[curr*2+1]==-1) break;
			else if (arr[curr*2]>arr[curr*2+1]) curr=curr*2;
			else curr=curr*2+1;
		}
		
		if (curr<m) break;
		
		ans.push_back(i);
		
		val=-1;
		while (curr!=i){
			swap(arr[curr],val);
			curr>>=1;
		}
		swap(arr[curr],val);
	}
	
	dfs(i*2);
	dfs(i*2+1);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		ans.clear();
		cin>>n>>m;
		
		n=1<<n;
		m=1<<m;
		
		for (int x=1;x<n;x++) cin>>arr[x];
		for (int x=n;x<(n<<1);x++) arr[x]=-1;
		
		dfs(1);
		
		ll val=0;
		
		for (int x=1;x<m;x++) val+=arr[x];
	
		cout<<val<<endl;
		for (auto &it:ans) cout<<it<<" ";
		cout<<endl;
	}
	
}