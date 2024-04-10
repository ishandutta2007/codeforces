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
int T,n,x,a[N];
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1,greater<int>());
		int ans=0,cnt=0;
		for(int i=1;i<=n;++i){
			++cnt;
			if(1LL*a[i]*cnt>=x){
				cnt=0,++ans;
			}
		}
		printf("%d\n",ans);;
	}
	return 0;
}