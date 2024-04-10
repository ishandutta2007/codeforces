#include<cstdio> 
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
LL read(){LL x;scanf("%lld",&x);return x;}
//int a[100]={};
int main(){
	LL n=read(),q=read();
//	for(int i=0;i<n;i++)a[2*i+1]=i+1;
//	for(int i=2*n-1;i>=1;--i)if(a[i]){
//		int j=i;
//		for(;j>=1;--j)if(a[j]==0)break;
//		if(j)a[j]=a[i],a[i]=0,cout<<j<<" "<<i<<endl;
//		else break;
//		for(int i=1;i<=2*n;i++)cout<<a[i]<<" ";cout<<endl;
//	}
//	for(int i=1;i<=2*n;i++)cout<<a[i]<<" ";cout<<endl;
	for(int i=0;i<q;i++){
		LL x=read();
		while(x%2==0)x=x/2+n;
		cout<<(x+1)/2<<endl;
	}
}