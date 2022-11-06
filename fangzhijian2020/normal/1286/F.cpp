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
int n,f[1<<20],t[1<<20],size[1<<20];long long a[1<<20],sum[1<<20],tmp;
long long Abs(long long x){return x<0?-x:x;}
int main(){
	n=read();
	for(int i=0;i<n;++i)a[1<<i]=read();
	for(int i=1;i<(1<<n);++i){
		size[i]=size[i>>1]+(i&1);
		sum[i]=sum[i^(i&-i)]+a[i&-i];
		if(size[i]==1&&a[i]==0)t[i]=1;
	}
	for(int i=1;i<(1<<n);++i){
		for(int j=(i-1)&i;(j<<1)>=i;j=(j-1)&i){
			if((tmp=Abs(sum[j]-sum[i^j]))<size[i]&&((size[i]+tmp)&1)){
				t[i]=1;break;
			}
		}
	}
	for(int i=1;i<(1<<n);++i){
		if(!f[i]&&t[i]){
			f[i]=1;int s=((1<<n)-1)^i;
			for(int j=s;j;j=(j-1)&s){
				f[i^j]=max(f[i^j],f[j]+1);
			}
		}
	}
	cout<<n-f[(1<<n)-1];
}