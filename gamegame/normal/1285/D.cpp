#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100001];
vector<int>all;
int solve(int bit,vector<int>v){
	if(v.empty()) return -1e9;
	if(bit==-1) return 0;
	vector<int>v1,v2;
	for(auto cur:v){
		if(cur&(1<<bit)) v1.push_back(cur);
		else v2.push_back(cur);
	}
	if(v1.empty() || v2.empty()){
		return max(solve(bit-1,v1),solve(bit-1,v2));
	}
	else{
		return min(solve(bit-1,v1),solve(bit-1,v2))+(1<<bit);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		all.push_back(a[i]);
	}
	int ans=solve(29,all);
	cout << ans << endl;
}