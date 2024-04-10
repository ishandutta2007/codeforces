#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int,2> pr;
const int mod=998244353;
int n,a[200005];
void Solve(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	if(abs(sum)&1){
		return puts("-1"),void();
	}
	vector<pr> ans;
	for(int i=1,j;i<=n;i=j+1){
		if(a[i]==0){
			j=i;
			ans.push_back((pr){i,i});
			continue;
		}
		j=i+1;
		while(a[j]==0)j++;
		if(a[i]!=a[j]){
			for(int k=i;k<=j;k++)ans.push_back((pr){k,k});
			continue;
		}
		for(int k=i;k<=j-2;k++)ans.push_back((pr){k,k});
		ans.push_back((pr){j-1,j});
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i[0]<<' '<<i[1]<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}