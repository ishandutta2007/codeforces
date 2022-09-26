#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int n,k,T,a[2333];
int Solve(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		ans+=(k-a[i])/a[1];
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}