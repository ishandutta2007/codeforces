#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll x,a[N]; 
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1,greater<ll>());
		ll cnt=0,sum=0;
		int ans=0;
		for(int i=1;i<=n;++i){
			sum+=a[i];
			++cnt;
			if(cnt*x>sum){
				break;
			}
			++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}