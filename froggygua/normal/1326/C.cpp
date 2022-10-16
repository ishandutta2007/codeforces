#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
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
ll ans,tot;
int n,k,las;
int main(){
	n=read(),k=read();
	las=0;
	ans=1;
	for(int i=1;i<=n;++i){
		int x=read();
		if(x>=n-k+1){
			tot+=x;
			if(las)ans*=(i-las),ans%=mod;
			las=i;
		}
	}
	cout<<tot<<" "<<ans%mod<<endl;
	return 0;
}