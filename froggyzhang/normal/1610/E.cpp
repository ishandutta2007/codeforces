#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int j=i;
		while(j<n&&a[j+1]==a[i])++j;
		if(j==n)ans=max(ans,j-i+1);
		else{
			int l=a[i],r=a[j+1];
			int now=j-i+2;
			while("myhmd"){
				int t=lower_bound(a+1,a+n+1,2*r-l)-a;
				if(t>n)break;
				++now;
				r=a[t];	
			}
			ans=max(ans,now);
		}
		i=j;
	}
	cout<<n-ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}