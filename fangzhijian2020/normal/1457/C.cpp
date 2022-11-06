#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1e9;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,p,k,x,y,f[100005],tmp,answer;char c[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();p=read();k=read();answer=1e9;
		scanf("%s",c+1);x=read();y=read();
		for(int i=0;i<=n;++i)f[i]=INF;tmp=0;
		for(;p<=n;++p){f[p]=tmp+(c[p]=='0')*x;tmp+=y;}
		for(int i=1;i<=n;++i){
			if(i-k>0){
				f[i]=min(f[i],f[i-k]+(c[i]=='0')*x);
			}
		}
		for(int i=n;i>max(0,n-k);--i){
			answer=min(answer,f[i]);
		}
		printf("%d\n",answer);
	}
	return 0;
}