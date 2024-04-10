#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,x;long long f[100005][2],h[100005];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		x=read();h[x]+=x;
	}
	for(int i=1;i<=N;++i){
		f[i][0]=max(f[i-1][1],f[i-1][0]);
		f[i][1]=f[i-1][0]+h[i];
	}
	cout<<max(f[N][0],f[N][1]);
	return 0;
}