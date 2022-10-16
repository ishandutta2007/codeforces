#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
int n,m;
void Solve(){
	scanf("%d%d",&n,&m);
	ll mn=4e18,mx=-1,mnp=0;
	for(int i=1;i<=n;i++){
		ll s=0,x,sum=0;
		for(int j=1;j<=m;j++){
			scanf("%lld",&x);
			s+=x,sum+=s;
		}
		if(sum>mx)mx=sum;
		if(sum<mn)mn=sum,mnp=i;
	}
	cout<<mnp<<' '<<mx-mn<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}