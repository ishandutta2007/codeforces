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
int T,n;
ll a[N];
bool check(int x){
	ll las=a[1];
	for(int i=2;i<=n;++i){
		ll tmp=a[i];	
		for(int j=x;j>=1;--j){
			if(tmp+(1LL<<(j-1))-1<las){
				tmp+=(1LL<<(j-1));
			}
		}
		if(tmp<las)return false;
		las=tmp;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=0;;++i){
			if(check(i)){
				printf("%d\n",i);
				break;
			}
		}
	}
//	getchar(),getchar();
	return 0;
}