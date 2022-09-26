#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
ll T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		ll tmp=1;
		bool ok=0;
		while(!ok){
			for(int j=1;j<=9;j++){
				ll p=(tmp*10-1)/9*j;
			//cout<<p<<endl;
			    if(p>n){
			    	ok=1;break;
				}
			    ++ans;
			}
			tmp=tmp*10;
		}
		cout<<ans<<endl;
	}
	return 0;
}