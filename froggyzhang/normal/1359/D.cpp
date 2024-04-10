#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int f[N],n,s[N],ans,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int t=30;t>=-30;--t){
		int mn=1e9;
		for(int i=1;i<=n;++i){
			if(a[i]>t){mn=1e9;continue;}
			mn=min(mn,s[i-1]);
			ans=max(ans,s[i]-mn-t);
		}
	}
	cout<<ans<<'\n';
	return 0;
}