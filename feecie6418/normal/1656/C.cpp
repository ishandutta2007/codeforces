#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[200005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	bool has0=0,has1=0;
	for(int i=1;i<=n;i++)has0|=a[i]==0,has1|=a[i]==1;
	if(has0&&has1)return puts("No"),void();
	if(!has1)return puts("Yes"),void();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)if(a[i]==a[i-1]+1)return puts("No"),void();
	puts("Yes");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}