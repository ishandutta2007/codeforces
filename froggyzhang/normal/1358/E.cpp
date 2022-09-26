#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000010
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
int n,a[N],s[N];
ll sum,qwq,p[N],x;
int main(){
	n=read();
	for(int i=1;i<=(n+1)/2;++i){
		a[i]=read();
		sum+=a[i];
		p[i]=p[i-1]+a[i];
	}
	x=read();
	sum+=x*(n/2);
	if(sum>0){
		printf("%d\n",n);
		return 0;
	}
	if(x>=0){
		printf("-1\n");
		return 0;
	}
	for(int i=(n+1)/2;i>=1;--i){
		qwq+=a[i];
		if(qwq<=0){
			++s[1],--s[n-i+2];
		}
		else{
			ll pos=(n+1)/2+(qwq-1)/(-x);
			pos=min(pos,n*1LL);
			++s[pos-i+2],--s[n-i+2];
		}
	}
	for(int i=1;i<=n;++i){
		s[i]+=s[i-1];
		if(!s[i]&&(i>n/2)){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}