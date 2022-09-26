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
int T;
ll n,l,r;
int main(){
	T=read();
	while(T--){
		n=read(),l=read(),r=read();
		ll now=1,p=1;
		while(now+2*(n-p)<l){
			now+=2*(n-p);
			++p;
		}
		ll pos=p+1,op=0;
		while(now<=r){
			if(now==1LL*n*(n-1)+1){
				printf("1");
				break;
			}
			if(pos==n+1){
				++p,op=0,pos=p+1;
				continue;
			}
			if(op){
				if(now>=l)printf("%I64d ",pos);
				++pos;
			}
			else{
				if(now>=l)printf("%I64d ",p);
			}
			op^=1;
			++now;
		}
		printf("\n");
	} 
	return 0;
}