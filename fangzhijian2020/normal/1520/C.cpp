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
int T,n,ans[2005][2005],tot;
int main(){
	T=read()+1;
	while(--T){
		n=read();
		if(n==1){
			puts("1");
		}	
		else if(n==2){
			puts("-1");
		}
		else if(n==3){
			puts("2 9 7");
			puts("4 6 3");
			puts("1 8 5");
		}
		else{
			tot=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;j+=2){
					ans[i][j]=++tot;
				}
			}
			for(int i=1;i<=n;++i){
				for(int j=2;j<=n;j+=2){
					ans[i][j]=++tot;
				}
			}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					cout<<ans[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}