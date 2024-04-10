#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int n,k,a[N],l,r,ans;
int calc(int l,int r,int x){
	int cnt=0;
	for(int i=l;i<=r;++i){
		if(a[i]<=x){
			++i,++cnt;
		}
	}
	return cnt;
}
bool check(int x){
	if(k&1){
		return (calc(2,n-1,x)>=k/2)||(calc(1,n,x)>=(k+1)/2);
	}
	else{
		return (calc(1,n-1,x)>=k/2)||(calc(2,n,x)>=k/2);
	}
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	l=1,r=1e9+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}