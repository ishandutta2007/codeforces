#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
#define Maxn 305
int a[Maxn][Maxn];
int b[Maxn][Maxn];
int nx[4]={-1,1,0,0};
int ny[4]={0,0,-1,1};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
	    for(int i=1;i<=n;++i)
	        for(int j=1;j<=m;++j){
	        	b[i][j]=0;
	        	for(int k=0;k<4;++k)
	        	    if(i+nx[k]>=1&&i+nx[k]<=n&&j+ny[k]>=1&&j+ny[k]<=m)b[i][j]++;
			}
		bool flag=true;
		for(int i=1;i<=n;++i)
		    for(int j=1;j<=m;++j){
		    	scanf("%d",&a[i][j]);
		        if(a[i][j]>b[i][j])flag=false;	
			}
		if(!flag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)printf("%d ",b[i][j]);
			puts("");
		}
	}
	return 0;
}