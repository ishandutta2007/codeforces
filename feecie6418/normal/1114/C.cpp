#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long Min=2e18,n,k;
void prime(long long nn,long long kk){
	long long minn=0;
	int tmp=log(n)/log(nn);
	for(long long i=nn,t=1;t<=tmp;i*=nn,t++)minn+=n/i;
	Min=min(Min,minn/kk);
}
void P(long long int nn){
	for(int i=2;i<=sqrt(nn);i++){
		if(nn%i==0){
			int q=0;
			while(nn%i==0){
				q++;
				nn/=i;
			}
			prime(i,q);
		}
	}
	if(nn!=1)prime(nn,1);
}
int main(){
	//cout<<(long)2*3*5*7*11*13*18*19;
	//freopen("factorial.in","r",stdin);
	//freopen("factorial.out","w",stdout);
	cin>>n;
	cin>>k;
	P(k);
	cout<<Min;
	return 0;
}