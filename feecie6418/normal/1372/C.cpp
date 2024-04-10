#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,a[200005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=0,r=n+1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			l=i;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]!=i){
			r=i;
			break;
		}
	}
	if(l==0)return puts("0"),void();
	for(int i=l;i<=r;i++)if(a[i]==i)return puts("2"),void();
	puts("1");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}