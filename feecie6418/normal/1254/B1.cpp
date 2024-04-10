#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<int> ve;
const int mod=998244353;
int n,a[100005],m;
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x)a[++m]=i;
	}
	if(m==1)return puts("-1"),0;
	ll ans=1e18;
	for(int i=2;i<=m;i++){
		if(m%i)continue;
		ll sum=0;
		for(int j=1;j<=m;j+=i){
			int l=j,r=(j+i-1),mid=(l+r)/2;
			for(int k=l;k<=r;k++)sum+=abs(a[k]-a[mid]);
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}