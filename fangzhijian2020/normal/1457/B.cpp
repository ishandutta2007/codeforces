#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,k,c[100005],tmp[100005],tot,answer;
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();answer=1e9;
		for(int i=1;i<=n;++i){
			c[i]=read();tmp[++tot]=c[i];
		}
		sort(tmp+1,tmp+tot+1);tot=unique(tmp+1,tmp+tot+1)-tmp-1;
		for(int i=1;i<=tot;++i){
			int Next=0,ans=0;
			for(int j=1;j<=n;++j){	
				if(c[j]==tmp[i])Next=max(Next,j);
				else{if(Next<j)Next+=k,++ans;}	
			}
			answer=min(ans,answer);
		}
		printf("%d\n",answer);
	}
	return 0;
}