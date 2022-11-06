#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,opt[10],tmp[10][10],tot;char c[305][305];
int main(){
	T=read()+1;
	while(--T){
		n=read();tot=0;memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=n;++i){
			scanf("%s",c[i]+1);
		}
		for(int p=2;p<=2*n;++p){
			for(int i=1;i<=n;++i){
				int j=p-i;
				if(j>0&&j<=n){
					if(c[i][j]=='O')++tmp[1][p%3];
					if(c[i][j]=='X')++tmp[2][p%3];
					if(c[i][j]!='.')++tot;
				}
			}
		}
		opt[0]=1;opt[1]=2;opt[2]=3;
		do{
			if(tmp[opt[0]][0]+tmp[opt[1]][1]+tmp[opt[2]][2]<=tot/3)break;
		}while(next_permutation(opt,opt+3));
		for(int p=2;p<=2*n;++p){
			for(int i=1;i<=n;++i){
				int j=p-i;
				if(j>0&&j<=n){
					if(c[i][j]!='.'&&opt[p%3]==1)c[i][j]='X';
					if(c[i][j]!='.'&&opt[p%3]==2)c[i][j]='O';
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				putchar(c[i][j]);
			}
			puts("");
		}
	}
	return 0;
}