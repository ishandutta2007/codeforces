#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||'9'<c)opt|=c=='-',c=getchar();
	while('0'<=c&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
long long Read(){
	long long a=0,opt=0;char c=getchar();while(c<'0'||'9'<c)opt|=c=='-',c=getchar();
	while('0'<=c&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,q;long long p;
long long solve(long long n,int p){
	long long ans=1;
	while(n%p==0){
		ans=ans*p;n/=p;
	}
	return ans;
}
int main(){
	T=read()+1;
	while(--T){
		p=Read();q=read();
		if(p%q!=0)printf("%lld\n",p);
		else{
			long long ans=1;
			for(int i=2;i*i<=q;++i){
				if(q%i==0){
					long long tmp=1;
					while(q%i==0){
						q=q/i;tmp=tmp*i;
					}
					ans=max(ans,p/solve(p,i)*tmp/i);
				}
			}
			if(q!=1){
				ans=max(ans,p/solve(p,q));
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}