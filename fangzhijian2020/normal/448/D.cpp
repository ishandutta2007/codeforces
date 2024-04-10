#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m;long long k,l,r,mid;
long long check(long long t){
	long long tmp=0;
	for(int i=1;i<=n;++i){
		tmp+=min(1ll*m,t/i);
	}
	return tmp;
}
int main(){
	n=read();m=read();k=read();
	l=1;r=1ll*n*m;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)>=k)r=mid-1;
		else l=mid+1;
	}
	cout<<r+1<<"\n";
	return 0;
}