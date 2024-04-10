#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1010
typedef long long ll;
const ll mod=1e9+7;
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
int mp[N][N],n,m;
ll cnt;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			mp[i][j]=1;
		}
		mp[i][x+1]=-1;
	}
	for(int i=1;i<=m;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			if(mp[j][i]==-1){
				cout<<0<<endl;
				return 0;
			}
			mp[j][i]=1;
		} 
		if(mp[x+1][i]==1){
			cout<<0<<endl;
			return 0;
		}
		mp[x+1][i]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==0)cnt++;
		} 
	}
	printf("%I64d\n",qpow(2,cnt));
	return 0;
}