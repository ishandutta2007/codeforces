#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m;
ll ans=0;
vector<int> xx[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1,x;j<=m;j++){
			scanf("%d",&x);
			xx[x].push_back(i);
			xx[x+100000].push_back(j);
		}
	}
	for(int i=1;i<=200000;i++){
		sort(xx[i].begin(),xx[i].end());
		ll s1=0,s2=0;
		for(int j:xx[i]){
			ans+=s2*j-s1;
			s2++,s1+=j;
		}
	}
	cout<<ans;
}
int main(){
	int t=1;
	while(t--)Solve();
}