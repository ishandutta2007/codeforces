#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define N 200010
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
int n,m;
int buc[N],a[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		buc[a[i]%m]++;
	}
	for(int i=0;i<m;i++){
		if(buc[i]>1){
			printf("0\n");
			return 0;
		}
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=ans*abs(a[i]-a[j])%m;
		}
	}
	cout<<ans<<endl;
	return 0;
}