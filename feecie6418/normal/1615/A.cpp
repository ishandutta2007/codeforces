#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int B=150005;
int n,a[105];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	if(a[n]%n)puts("1");
	else puts("0");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}