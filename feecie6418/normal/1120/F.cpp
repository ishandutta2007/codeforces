#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,c,d,t[100005];
char ch[100005];
int main(){
	cin>>n>>c>>d;
	for(int i=1;i<=n;i++)cin>>t[i]>>ch[i];
	cin>>t[n+1];
	ll ans=1e18,cursum=0;
	for(int i=n+1,lst=0;i>=1;i--){
		if(i<n&&ch[i]==ch[i+1])cursum+=min(d,c*(lst-t[i+1]));
		if(ch[i]!=ch[i-1])lst=t[i];
		ll s=(t[n+1]-t[i])*c+(i-1ll)*d+cursum;
		ans=min(ans,s);
	}
	cout<<ans;
}