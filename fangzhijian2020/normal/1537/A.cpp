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
int T,n,sum,t;
int main(){
	T=read()+1;
	while(--T){
		n=read();sum=0;
		for(int i=1;i<=n;++i){
			t=read();sum+=t;
		}
		if(sum==n){
			puts("0");continue;
		}
		if(sum<n){
			puts("1");continue;
		}
		t=0;
		while(sum!=n){
			++n;++t;
		}
		cout<<t<<"\n";
	}
	return 0;
}