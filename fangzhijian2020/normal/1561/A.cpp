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
int T,n,a[1005];
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=2*n+1;++i){
			int opt=1;
			for(int j=1;j<n;++j){
				if(a[j]>a[j+1])opt=0;
			}
			if(opt){
				cout<<i-1<<"\n";break;
			}
			if(i&1){
				for(int j=1;j<n;j+=2){
					if(a[j]>a[j+1])swap(a[j],a[j+1]);
				}
			}
			else{
				for(int j=2;j<n;j+=2){
					if(a[j]>a[j+1])swap(a[j],a[j+1]);
				}
			}
		}
	}
	return 0;
}