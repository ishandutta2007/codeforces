#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 3030
const int mod=998244353;
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
int n,m;
char s[N],t[N];
int dp[N][N];
inline int qwq(int x,int y){
	return y<=m?(s[x]==t[y]):1;
}
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;++i){
		dp[i][i]=qwq(1,i); 
	}
	int ans=(m==1)?dp[1][1]:0;
	for(int i=2;i<=n;++i){
		int l=1,r=i-1;
		while(r<=n){
			if(l&&qwq(i,l-1)){
				dp[l-1][r]=(dp[l-1][r]+dp[l][r])%mod;
			}
			if(r<n&&qwq(i,r+1)){
				dp[l][r+1]=(dp[l][r+1]+dp[l][r])%mod;
			}
			++l,++r;
		}
		if(i>=m)ans=(ans+dp[1][i])%mod;
	}
	printf("%d\n",(ans+ans)%mod);
	return 0;
}