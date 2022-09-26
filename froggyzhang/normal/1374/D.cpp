#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 200020
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
int T,n,k,a[N];
map<int,ll> mp;
int main(){
	T=read();
	while(T--){
		mp.clear();
		n=read(),k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]%k==0)continue;
			if(mp.count(a[i]%k)){
				mp[a[i]%k]+=k;
			}
			else{
				mp[a[i]%k]=k-a[i]%k+1;
			}
		}
		ll ans=0;
		for(auto x:mp){
			ans=max(x.second,ans);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}