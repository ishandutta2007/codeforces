#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,a[100005];long long b[100005],Max;
int main(){
	T=read()+1;
	while(--T){
		n=read();Max=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(i>1)b[i]=max(0ll,b[i-1]+a[i-1]-a[i]);
			Max=max(Max,b[i]);
		}
		int j;
		for(j=0;(1ll<<j)-1<Max;++j);
		cout<<j<<"\n";
	}
	return 0;
}