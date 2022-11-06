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
int T,n,a[100005],t[100005],tot;long long ans,sum;
int main(){
	T=read()+1;
	while(--T){
		n=read();tot=0;ans=1e18;
		for(int i=1;i<=n;++i){
			a[i]=read()&1;
			if(a[i])t[++tot]=i;
		}
		if(abs(n-2*tot)>1)puts("-1");
		else{
			if(n&1){
				if(tot*2>n){
					sum=0;
					for(int i=1;i<=tot;++i){
						sum+=abs(t[i]-(2*i-1));
					}
				}
				else{
					sum=0;
					for(int i=1;i<=tot;++i){
						sum+=abs(t[i]-(2*i));
					}
				}
				cout<<sum<<"\n";
			}
			else{
				sum=0;
				for(int i=1;i<=tot;++i){
					sum+=abs(t[i]-(2*i-1));
				}
				ans=min(ans,sum);
				sum=0;
				for(int i=1;i<=tot;++i){
					sum+=abs(t[i]-(2*i));
				}
				ans=min(ans,sum);
				cout<<ans<<"\n";
			}	
		}
		
	}
	return 0;
}