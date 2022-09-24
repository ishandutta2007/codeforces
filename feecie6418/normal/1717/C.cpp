#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
void Solve(){
	scanf("%d",&n);
	int ok=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),ok&=(b[i]>=a[i]);
	for(int i=1;i<=n;i++){
		int x=b[i],y=b[i%n+1];
		if(x<=y+1||(x>y+1&&x==a[i]));
		else ok=0;
	}
	if(ok)puts("Yes");
	else puts("No");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}