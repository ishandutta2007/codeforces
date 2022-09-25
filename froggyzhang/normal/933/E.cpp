#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,a[N],pre[N];
ll dp[N];
vector<int> ans;
void Move(int x){
	if(!a[x]||!a[x+1]||x==n)return;
	ans.push_back(x);
	int t=min(a[x],a[x+1]);
	a[x]-=t,a[x+1]-=t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dp[2]=a[1];
	for(int i=3;i<=n+1;++i){
		ll w1=dp[i-3]+max(a[i-1],a[i-2]);
		ll w2=dp[i-2]+a[i-1];
		if(w1<w2)dp[i]=w1,pre[i]=i-3;
		else dp[i]=w2,pre[i]=i-2;
	}
	int i=dp[n]<dp[n+1]?n:n+1;
	for(;i>1;i=pre[i]){
		if(pre[i]==i-3){
			Move(i-2),Move(i-1);
			if(i>3)Move(i-3);	
		}
		else{
			Move(i-1);if(i>2)Move(i-2);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	return 0;
}