#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll f[105][105][105],a[105];
char s[105];
ll dp(int l,int r,int k){
	if(l>r)return 0;
	if(f[l][r][k])return f[l][r][k];
	for(int i=l;i<r;i++)if(s[i]==s[r])f[l][r][k]=max(f[l][r][k],dp(i+1,r-1,0)+dp(l,i,k+1));
	f[l][r][k]=max(f[l][r][k],dp(l,r-1,0)+a[k+1]);
	return f[l][r][k];
}
int main(){
	cin>>n>>s+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++)a[i]=max(a[i],a[j]+a[i-j]);
	}
	cout<<dp(1,n,0);
    return 0;
}