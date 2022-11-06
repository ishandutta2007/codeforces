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
int T,n,k,A,B;
long long C(int n,int m){
	long long ans=1;
	for(int i=1;i<=m;++i){
		ans=1ll*ans*(n-i+1);
		ans=ans/i;
	}
	return ans;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();A=n-2;B=2;
		for(int i=1;i<=n;++i){
			if(C(A+B-1,B)>=k){
				putchar('a');--A;
			}
			else{
				k-=C(A+B-1,B);
				putchar('b');--B;
			}
		}
		puts("");
	}
	return 0;
}