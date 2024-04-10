#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,a[100005],mx[100005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],mx[i]=max(mx[i-1],a[i]);
	for(int i=n,lst=n;i>=1;i--){
		if(a[i]==mx[i]){
			for(int j=i;j<=lst;j++)cout<<a[j]<<' ';
			lst=i-1;
		}
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}