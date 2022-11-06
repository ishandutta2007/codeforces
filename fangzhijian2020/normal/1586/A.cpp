#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,a[105],sum;
int main(){
	T=read()+1;
	while(--T){
		n=read();sum=0;
		for(int i=1;i<=n;++i){
			a[i]=read();sum+=a[i];
		}
		int opt=0;
		for(int i=2;i*i<=sum;++i){
			if(sum%i==0){
				opt=1;break;
			}
		}
		if(opt){
			cout<<n<<"\n";
			for(int i=1;i<=n;++i)cout<<i<<" ";
		}
		else{
			cout<<n-1<<"\n";
			for(int i=1;i<=n;++i){
				if((a[i]&1)&&!opt){
					opt=1;continue;
				}
				cout<<i<<" ";
			}	
		}
		puts("");
	}
	return 0;
}