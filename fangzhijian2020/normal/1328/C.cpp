#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,a[50005],b[50005];char c[50005];
int main(){
	T=read()+1;
	while(--T){
		n=read();scanf("%s",c+1);
		int opt=0;
		for(int i=1;i<=n;++i){
			if(c[i]=='0'){a[i]=b[i]=0;}
			if(c[i]=='1'){
				if(opt==1){
					a[i]=0;b[i]=1;
				}
				else{
					a[i]=1;b[i]=0;opt=1;
				}
			}
			if(c[i]=='2'){
				if(!opt){
					a[i]=b[i]=1;
				}
				else{
					a[i]=0;b[i]=2;
				}
			}
		}
		for(int i=1;i<=n;++i)putchar(a[i]+'0');puts("");
		for(int i=1;i<=n;++i)putchar(b[i]+'0');puts("");
	}
	return 0;
}