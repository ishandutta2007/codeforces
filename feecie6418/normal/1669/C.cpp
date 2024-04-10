#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
void Solve(){
	cin>>n;
	bool ok=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2!=a[i%2]%2)ok=0;
	}
	if(ok)puts("YES");
	else puts("NO");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}