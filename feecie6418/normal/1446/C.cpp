#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt=1,c[7000005][2],s[7000005];
void Insert(int p){
	int now=1,m[34]={0};
	while(p)m[++m[0]]=p%2,p/=2;
	for(int i=31;i>=1;i--){
		if(!c[now][m[i]])c[now][m[i]]=++cnt;
		now=c[now][m[i]],s[now]++;
	}
}
int n,a[200005];
int dp(int x){
	if(s[x]==1||!x)return 0;
	int ans=1e9;
	ans=min(ans,dp(c[x][0])+max(s[c[x][1]]-1,0));
	ans=min(ans,dp(c[x][1])+max(s[c[x][0]]-1,0));
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Insert(a[i]);
	}
	cout<<dp(1);
	return 0;
}