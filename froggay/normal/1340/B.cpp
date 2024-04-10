#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2010
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
int n,k,a[N],cnt[N];
char s[10];
bool dp[N][N];
int num[10]={119,18,93,91,58,107,111,82,127,123};
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		int x=0;
		scanf("%s",s+1);
		for(int j=1;j<=7;++j){
			x=(x<<1)|(s[j]-'0');
		}
		a[i]=x;
	}
	for(int i=0;i<=1000;++i){
		cnt[i]=(cnt[i>>1]+(i&1));
	}
	dp[n+1][0]=1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<=9;++j){	
			if((num[j]&a[i])==a[i]){
				int tmp=cnt[(num[j]^a[i])];
				for(int p=k;p>=tmp;--p){
					dp[i][p]|=dp[i+1][p-tmp];
				}
			}
		}
	}
	if(!dp[1][k]){
		printf("-1\n");
		return 0;
	}
	int now=k;
	for(int i=1;i<=n;++i){
		for(int j=9;j>=0;--j){
			if((num[j]&a[i])==a[i]){
				int o=cnt[num[j]^a[i]];
				if(o>now)continue;
				if(dp[i+1][now-o]){
					now-=o;
					putchar(j+'0');
					break;
				}
			}
		}
	}
	return 0;
}