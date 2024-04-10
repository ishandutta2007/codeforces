#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 111
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
ll T,n,m,k,h[N];
int main(){
	T=read();
	while(T--){
		bool ok=1;
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++){
			h[i]=read();
		}
		if(n==1){
			printf("YES\n");
			continue;
		}
		for(int i=1;i<n;i++){
			if(h[i+1]-h[i]>=k){
				m-=h[i+1]-h[i]-k;
				if(m<0){
					ok=0;
					printf("NO\n");
					break;
				}
			}
			else{
				m+=min(h[i],k+(h[i]-h[i+1]));
			}
		}
		if(ok){
			printf("YES\n");
		}
	}
	return 0;
}