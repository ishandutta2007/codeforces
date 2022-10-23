#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int,2> pr;
const int mod=998244353;
int n,a[200005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n&1){
		return puts("-1"),void();
	}
	vector<pr> ans;
	for(int i=1;i<=n;i+=2){
		if(a[i]==a[i+1])ans.push_back((pr){i,i+1});
		else ans.push_back((pr){i,i}),ans.push_back((pr){i+1,i+1});
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i[0]<<' '<<i[1]<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}