#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 123
inline ll read(){
    ll x=0,f=1;
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
ll k,a[N],cnt[N];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		bool ok=true;
		for(int i=1;i<=n;i++){
			if(!ok)break;
			int now=0;
			while(a[i]){
				cnt[now]+=a[i]%k;
				if(cnt[now]>1){
					ok=false;
					printf("NO\n");
					break;
				}
				a[i]/=k;
				++now;
			}
		}
		if(ok){
			printf("YES\n");
		}
	}
	return 0;
}