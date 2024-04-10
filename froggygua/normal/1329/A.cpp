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
int n,m,l[N],p[N];
ll sum;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		l[i]=read();
		sum+=l[i];
	}
	if(sum<n){
		printf("-1\n");
		return 0;
	}
	int now=n;
	for(int i=m;i>=1;--i){
		if(now<1){
			printf("-1\n");
			return 0;
		}
		p[i]=min(now,n-l[i]+1);
		now=p[i]-1;
	}
	if(now>0){
		int las=0;
		for(int i=1;i<=m;++i){
			p[i]=las+1;
			if(p[i]+l[i]>=p[i+1])break;
			las=p[i]+l[i]-1;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",p[i]);
	}
	return 0;
}