#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int T,a[N],b[N],n;
bool Solve(){
	for(int i=1;i<=n;++i){
		a[i]=b[i]=read();
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		if(a[i]^b[i]&&a[i]%b[1]){
			return false;
		}
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read();
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}