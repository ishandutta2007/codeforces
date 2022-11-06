#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,x,size[505],Pow[505],ans;
int main(){
	n=read();Pow[0]=1;
	for(int i=1;i<=n;++i){
		Pow[i]=Pow[i-1]*2%mod;
		x=read();if(x>0)++size[x];
	}
	ans=Pow[n-1]-1;
	for(int i=1;i<=n;++i){
		ans=(ans-Pow[size[i]]+1+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}