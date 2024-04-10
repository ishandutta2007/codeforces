#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200020
typedef long long ll;
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
int T,n,a[N],m,b[N];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=m;++i){
			b[i]=read();
		}
		sort(b+1,b+m+1);
		sort(a+1,a+n+1,greater<int>());
		ll ans=0;
		int pos=m;
		for(int i=1;i<=m;++i){
			ans+=a[i];
			if(!--b[i])ans+=a[i];
			else{
				while(b[i]--)++pos;
				ans+=a[pos];
			}	
		}
		printf("%I64d\n",ans);
	} 
	return 0;
}