#include<iostream>
#include<cstdio>
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
		int ans=0;
		while(n){
			int l=0,r=1e8,now=0;
			while(l<r){
				int mid=(l+r)>>1;
				if(3LL*mid*(mid+1)/2-mid<=n){
					now=mid;
					l=mid+1;
				}
				else{
					r=mid;
				}
				
			}
			if(!now)break;
			n-=3LL*now*(now+1)/2-now;
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}