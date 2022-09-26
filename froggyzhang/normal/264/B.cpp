#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm> 
using namespace std;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],m;
vector<int> fac[N];
int dp[N],d[N]; 
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		m=max(m,a[i]);
	}
	sort(a+1,a+n+1); 
	for(int i=2;i<=m;i++){
		if(fac[i].empty()){
			for(int j=i;j<=m;j+=i){
				fac[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			dp[i]=1;
			continue;
		}
		for(int j=0;j<fac[a[i]].size();j++){
			dp[i]=max(dp[i],d[fac[a[i]][j]]+1);
		} 
		for(int j=0;j<fac[a[i]].size();j++){
			d[fac[a[i]][j]]=max(d[fac[a[i]][j]],dp[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
1 1 1
*/