#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 40040
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
int n,m,k,a[N],b[N],sa[N],sb[N];
ll ans; 
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
	}
	for(int i=1;i<=n;++i){
		if(!a[i])continue;
		int j=i;
		while(a[i+1])++i;
		sa[i-j+1]++;
	}
	for(int i=1;i<=m;i++){
		if(!b[i])continue;
		int j=i;
		while(b[i+1])++i;
		sb[i-j+1]++;
	}
	for(int i=n;i>=1;i--)sa[i]+=sa[i+1];
	for(int i=m;i>=1;i--)sb[i]+=sb[i+1];
	for(int i=n;i>=1;i--)sa[i]+=sa[i+1];
	for(int i=m;i>=1;i--)sb[i]+=sb[i+1];
	for(int i=1;i<=n;i++){
		if(k%i==0&&k/i<=m){
			ans+=1LL*sa[i]*sb[k/i];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}