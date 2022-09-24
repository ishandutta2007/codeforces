#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,k,a[100005];
void Solve(){
	cin>>n>>k;
	map<int,int> mp;
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]=1,mx=max(mx,a[i]);
	if(!k)return cout<<n<<'\n',void();
	int mex=0;
	while(mp[mex])mex++;
	if(mex==mx+1)cout<<n+k<<'\n';
	else cout<<n+(!mp[(mx+mex+1)/2])<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}