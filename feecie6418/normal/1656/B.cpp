#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	set<int> s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s.insert(a[i]);
	for(int i=1;i<=n;i++)if(s.count(a[i]+m))return puts("Yes"),void();
	puts("No");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}