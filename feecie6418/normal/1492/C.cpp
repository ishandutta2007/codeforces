#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,mi[200005],mx[200005],ans=0;
char s[200005],t[200005];
int main(){
	cin>>n>>m>>s+1>>t+1;
	for(int i=1,j=1;i<=m;i++){
		while(s[j]!=t[i]&&j<=n)j++;
		mi[i]=j++;
	}
	for(int i=m,j=n;i;i--){
		while(s[j]!=t[i]&&j)j--;
		mx[i]=j--;
	}
	for(int i=1;i<m;i++)ans=max(ans,mx[i+1]-mi[i]);
	cout<<ans;
}