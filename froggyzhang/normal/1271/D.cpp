#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 5050
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int mx[N],n,m,k,a[N],b[N],c[N],tot,can[N];
int dp[N],ans;
vector<int> vec[N];
bool cmp(int x,int y){
	return c[x]>c[y];
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		mx[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		mx[v]=max(mx[v],u);
	}
	tot=k;
	for(int i=1;i<=n;i++){
		vec[mx[i]].push_back(i);
		if(tot<a[i]){
			cout<<-1<<endl;
			return 0;
		}
		can[i-1]=tot-a[i];
		tot+=b[i];
	}
	can[n]=n;
	for(int i=n-1;i>=1;i--){
		can[i]=min(can[i],can[i+1]);
	}
	for(int i=1;i<=n;i++){
		sort(vec[i].begin(),vec[i].end(),cmp);
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=can[i];j>=1;--j){
			int sum=0;
			for(int k=0;k<min((int)vec[i].size(),j);++k){
				sum+=c[vec[i][k]];
				dp[j]=max(dp[j],dp[j-k-1]+sum);
			}
		}
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}