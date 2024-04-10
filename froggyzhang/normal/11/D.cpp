#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
#define N 20
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
int n,mp[N][N],m;
ll dp[N][1<<N],ans;
int lowbit(int x){
	return x&(-x);
} 
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read()-1,v=read()-1;
		mp[u][v]=mp[v][u]=1;
	} 
	for(int i=0;i<n;i++){
		dp[i][1<<i]=1;
	} 
	for(int j=0;j<(1<<n);j++){
		for(int i=0;i<n;i++){
			if(!dp[i][j])continue;
			int u=(int)log2(lowbit(j));
			for(int k=0;k<n;k++){
				if(!mp[i][k])continue;
				if(k<u)continue;
				if((1<<k)&j){
					if(u==k)
					ans+=dp[i][j];
				}
				else{
					dp[k][j|(1<<k)]+=dp[i][j];
				}
			} 
		}
	} 
	printf("%lld\n",(ans-m)/2);
	return 0;
}