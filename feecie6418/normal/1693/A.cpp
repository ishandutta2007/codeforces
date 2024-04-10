#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll a[200005];
int n;
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
	if(a[n]!=0)return puts("No"),void();
	int lst=n;
	while(lst&&a[lst]==0)lst--;
	if(lst){
		for(int i=1;i<=lst;i++)if(a[i]<=0)return puts("No"),void();
	}
	puts("Yes");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}