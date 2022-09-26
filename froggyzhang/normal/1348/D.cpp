#include<iostream>
#include<cstdio>
#include<assert.h>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;
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
int T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		int p=1;
		while((1<<(p+1))-1<n)++p;
		printf("%d\n",p);
		int now=1;
		n-=p+1;
		for(int i=1;i<=p;++i){
			int l=0,r=now+1,ans=-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(1LL*(p+1-i)*mid<=n){
					l=mid+1,ans=mid;
				}
				else{
					r=mid;
				}
			}
			assert(ans>=0);
			printf("%d ",ans);
			n-=(p+1-i)*ans,now+=ans;
		}
		printf("\n");
	}
	return 0;
}