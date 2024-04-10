#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 2222
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
int n;
ll a[N],mx,ans[N],p[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		ll tmp=a[i],lim=a[i];
		p[i]=a[i];
		for(int j=i-1;j>=1;j--){
			p[j]=min(lim,a[j]);
			tmp+=min(lim,a[j]);
			lim=min(lim,a[j]);
		}
		lim=a[i];
		for(int j=i+1;j<=n;j++){
			p[j]=min(lim,a[j]);
			tmp+=min(lim,a[j]);
			lim=min(lim,a[j]);
		}
		if(tmp>mx){
			mx=tmp;
			for(int j=1;j<=n;j++){
				ans[j]=p[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}