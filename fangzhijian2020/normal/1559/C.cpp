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
int T,n,opt[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)opt[i]=read();opt[n+1]=1;
		int tmp=0;
		for(int i=1;i<=n;++i){
			if(opt[i]==0&&opt[i+1]==1){
				tmp=i;
			}
		}
		if(!tmp){
			cout<<n+1<<" ";
			for(int i=1;i<=n;++i)cout<<i<<" ";
			puts("");
		}
		else{
			for(int i=1;i<=tmp;++i){
				cout<<i<<" ";
			}
			cout<<n+1<<" ";
			for(int i=tmp+1;i<=n;++i){
				cout<<i<<" ";
			}
			puts("");
		}
	}
	return 0;
}