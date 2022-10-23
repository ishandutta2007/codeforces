#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,jc[1000005];
int main(){
	cin>>n,jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	int ans=jc[n];
	for(int i=1,w=1;i<n;i++){
		w=1ll*w*(n-i+1)%mod;
		ans=(ans+jc[n])%mod;
		ans=(ans-w+mod)%mod;
	}
	cout<<ans;
}