#include<iostream>
#include<cstdio>
#include<cstring>
#include<assert.h>
#include<cstdlib>
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
int n,ans[N];
inline int Get(int n){
	return (1LL*rand()*rand()+rand())%n+1;
}
int rd(int l,int r){
	return l+Get(r-l+1)-1;
}
void Solve(int l,int r){
	if(l>r)return;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x=read(),d=read();
	if(d==r-l+1){
		for(int i=l;i<=r;++i){
			ans[i]=x;
		}
		return;
	}
	if(d>(r-l+1)/2){
		int mid=(r+l)>>1;
		printf("? %d %d\n",l,mid);
		fflush(stdout);
		int u=read(),p=read();
		if(u==x){
			for(int i=mid-p+1;i<=mid+d-p;++i){
				ans[i]=u;
			}
			Solve(l,mid-p),Solve(mid+d-p+1,r);
			return;
		}
		printf("? %d %d\n",mid+1,r);
		fflush(stdout);
		u=read(),p=d-read();
		if(u==x){
			for(int i=mid-p+1;i<=mid+d-p;++i){
				ans[i]=u;
			}
			Solve(l,mid-p),Solve(mid+d-p+1,r);
			return;
		}
		assert(false);
	}
	else{
		int k=rd(l+d-1,r-d);
		Solve(l,k),Solve(k+1,r);
	}
}
int main(){
	n=read();
	Solve(1,n);
	printf("! ");
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}