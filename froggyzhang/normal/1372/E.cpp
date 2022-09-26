#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 110
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
int n,m,_l[N][N],_r[N][N],dp[N][N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int k=read();
		while(k--){
			int L=read(),R=read();
			for(int j=L;j<=R;++j){
				_l[i][j]=L,_r[i][j]=R;
			}
		}
	}
	for(int len=1;len<=m;++len){
		for(int l=1;l+len-1<=m;++l){
			int r=l+len-1;
			for(int k=l;k<=r;++k){
				int cnt=0;
				for(int i=1;i<=n;++i){
					if(_l[i][k]>=l&&_r[i][k]<=r){
						++cnt;
					}
				}
				dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+cnt*cnt);
			}
		}
	}
	printf("%d\n",dp[1][m]);
	return 0;
}