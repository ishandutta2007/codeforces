#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int n;
ll x[N],y[N],nx,ny;
ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read()*2,y[i]=read()*2;
	}
	if(n&1){
		printf("NO\n");
		return 0;
	}
	nx=(x[1]+x[1+n/2])/2,ny=(y[1]+y[1+n/2])/2;
	for(int i=2;i<=n/2;i++){
		if(((x[i]-nx)^(nx-x[i+n/2]))||((y[i]-ny)^(ny-y[i+n/2]))){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}