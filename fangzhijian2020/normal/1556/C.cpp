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
long long n,a[1005],ans=0;
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=2;i<=n;++i){
		if(!(i&1)){
			long long sum=0,Min=0;
			ans+=max(0ll,min(a[i-1],a[i])-max(-Min,1-sum)+1);
			for(int j=i;j<=n;++j){
				sum+=(j&1?a[j]:-a[j]);Min=min(Min,sum);
				if(j&1){
					ans+=max(0ll,min(a[i-1],a[j+1]-sum)-max(-Min,1-sum)+1);
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}