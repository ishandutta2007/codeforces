/*
 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int n,ans[2333][2333],cnt;
const int p[4][4]={
	{0,0,0,0},
	{0,1,2,6},
	{0,9,3,7},
	{0,4,5,8}
};
int main(){
	n=read();
	if(n<3){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			ans[i][j]=n*n-9+p[i][j];
		}
	} 
	for(int i=n;i>=4;--i){
		if(i&1){
			for(int j=1;j<=i;++j){
				ans[j][i]=++cnt;
			}
			for(int j=i-1;j>=1;--j){
				ans[i][j]=++cnt;
			}
		}
		else{
			for(int j=1;j<=i;++j){
				ans[i][j]=++cnt;
			}
			for(int j=i-1;j>=1;--j){
				ans[j][i]=++cnt;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}