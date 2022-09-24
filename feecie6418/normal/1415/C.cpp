#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p,k,s[200005],X,Y;
char str[200005];
void Solve(){
	cin>>n>>p>>k>>str+1>>X>>Y;
	for(int i=n;i>=1;i--){
		s[i]=s[i+k]+(str[i]=='0');
	}
	int ans=2e9;
	for(int i=1;i+p-1<=n;i++){
		ans=min(ans,(i-1)*Y+s[i+p-1]*X);
	}
	for(int i=n;i>=1;i--)s[i]=0;
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}