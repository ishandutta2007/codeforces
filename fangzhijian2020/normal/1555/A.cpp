#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T;long long n;
int main(){
	T=read()+1;
	while(--T){
		n=read();
		long long now=(n+1)/2;
		now=max(now,3ll);
		cout<<now*5<<"\n";
	}
	return 0;
}