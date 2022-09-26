#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100010
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
int n,a[N],b[N],t[N];
bool check(int x){
	int i=0;
	for(i=1;i<=x;++i){
		b[i<<1]=a[i];
	}
	int k=i;
	while(k<=n&&a[k]==a[1])++k;
	i=k;
	for(int j=1;j<=n;++i,j+=2){
		b[j]=a[i];
	}
	for(int j=x+1;(j<<1)<=n;++j,++i){
		if(i>n)i=x+1;
		b[j<<1]=a[i];
	}
	int tot=0;
	for(int i=2;i<n;++i){
		tot+=(b[i]<b[i-1]&&b[i]<b[i+1]);
	}
	return tot>=x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=t[i]=read();
	}
	sort(a+1,a+n+1);
	int l=1,r=(n-1)/2+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1,ans=mid;
			memcpy(t,b,sizeof(t));
		}
		else{
			r=mid;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		printf("%d ",t[i]);
	}
	return 0;
}