#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200010
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
int n,k;
int a[N],b[N],c[N],an,bn,cn,ans,now;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		int x=read(),A=read(),B=read();
		if(A&&B){
			c[++cn]=x;
		}
		else if(A){
			a[++an]=x;
		}
		else if(B){
			b[++bn]=x;
		}
	}
	if(an+cn<k||bn+cn<k){
		printf("-1\n");
		return 0;
	}
	sort(a+1,a+an+1);
	sort(b+1,b+bn+1);
	sort(c+1,c+cn+1);
	for(int i=1;i<=min(cn,k);++i){
		now+=c[i];
	} 
	for(int i=1;i<=k-min(cn,k);++i){
		now+=a[i]+b[i];
	}
	ans=now;
	int pos=k-min(cn,k);
	for(int i=min(cn,k);i>=1;--i){
		now-=c[i],++pos;
		if(pos>an||pos>bn)break;
		now+=a[pos]+b[pos];
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}