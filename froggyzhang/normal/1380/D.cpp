#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int n,m,x,k,y,a[N],b[N],pos[N];
ll ans;
int main(){
	n=read(),m=read();
	x=read(),k=read(),y=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		b[i]=read();
	}
	int now=1;
	for(int i=1;i<=m;++i){
		while(a[now]^b[i]&&now<=n)++now;
		if(now>n)return !printf("-1\n");
		pos[i]=now;
	}
	pos[m+1]=n+1;
	for(int i=0;i<=m;++i){
		if(pos[i]+1==pos[i+1])continue;
		int len=pos[i+1]-pos[i]-1,gu=0;
		for(int j=pos[i]+1;j<=pos[i+1]-1;++j){
			if(a[j]>a[pos[i]]&&a[j]>a[pos[i+1]])++gu;
		}
		gu=min(gu,1);
		while(gu>0){
			if(len<k)return !printf("-1\n");
			ans+=x,len-=k,gu-=k;
		}
		ans+=(x>=1LL*k*y?1LL*y*len:1LL*y*(len%k)+1LL*x*(len/k));
	}
	printf("%I64d\n",ans);
	return 0;
}