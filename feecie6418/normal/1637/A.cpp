#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[10005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)if(a[i]<a[i-1])return puts("YES"),void();
	puts("NO");
}
int main(){
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}