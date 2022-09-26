#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000060
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
int n,a[N],mx;
ll tot[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		tot[a[i]+n-i+1]+=a[i];
		mx=max(mx,a[i]+n-i+1);
	}
	for(int i=1;i<=mx;i++){
		ans=max(ans,tot[i]);
	}
	cout<<ans<<endl;
	return 0;
}