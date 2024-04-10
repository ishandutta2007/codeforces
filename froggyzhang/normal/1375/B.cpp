#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 555
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
int T,n,m,a[N][N],cnt[N][N];
const int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
inline int In(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=m;
}

void Solve(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cnt[i][j]=0;
			for(int k=0;k<4;++k){
				int nx=i+d[k][0],ny=j+d[k][1];
				cnt[i][j]+=In(nx,ny); 
			}
			if(a[i][j]>cnt[i][j]){
				printf("NO\n");
				return;
			}
		}
	} 
	printf("YES\n");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",cnt[i][j]);
		}
		printf("\n");
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		Solve();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=0;
			}
		}
	}
	return 0;
}