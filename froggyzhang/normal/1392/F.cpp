#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll; 
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n;
ll sum;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		sum+=read();
	}
	ll l=0,r=1e12+1,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if((mid+mid+n-1)*n/2<sum){
			l=mid+1;
		}
		else{
			r=ans=mid;
		}
	}
	int pos=(ans+ans+n-1)*n/2-sum;
	for(int i=1;i<=n;++i){
		printf("%I64d ",ans+i-1-((n-i+1)<=pos));
	}
	return 0;
}