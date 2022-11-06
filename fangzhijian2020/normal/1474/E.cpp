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
int T,n;long long sum;
long long mul(int x){
	return 1ll*x*x;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();sum=0;
		for(int i=1;i<n;++i){
			sum+=mul(max(i-1,n-i));
		}
		cout<<sum<<"\n";
		if(n==2){
			puts("2 1");
			puts("1");
			puts("2 1");
		}
		else if(n==3){
			puts("2 3 1");
			puts("2");
			puts("1 3");
			puts("3 2");
		}
		else{
			cout<<n/2+1<<" ";
			for(int i=3;i<=n/2;++i)cout<<i<<" ";
			cout<<1<<" ";
			for(int i=n/2+2;i<=n;++i)cout<<i<<" ";
			cout<<2<<"\n";
			cout<<n-1<<"\n";
			for(int i=n/2+1;i<n;++i){
				cout<<i<<" "<<1<<"\n";
			}
			for(int i=2;i<=n/2;++i){
				cout<<i<<" "<<n<<"\n";
			}
			cout<<1<<" "<<n<<"\n";
		}
		
	}
	return 0;
}