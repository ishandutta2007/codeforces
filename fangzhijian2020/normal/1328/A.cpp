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
long long T,a,b;
int main(){
	T=read()+1;
	while(--T){
		a=read();b=read();
		int tmp=(a+b-1)/b;
		cout<<1ll*tmp*b-a<<"\n";
	}
	return 0;
}