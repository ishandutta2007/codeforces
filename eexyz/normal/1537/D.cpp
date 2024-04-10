#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define db double
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int n,i,j,T,x,y,c,v,a[N],sum,mn;
//ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<"Bob\n";continue;
		}
		if((n&-n)==n){
			c=0;
			while(n%2==0)++c,n>>=1;
			if((c&1))cout<<"Bob\n";
			else cout<<"Alice\n";
		}
		else{
			if(n%2==0)cout<<"Alice\n";
			else cout<<"Bob\n";
		}
	}
	return 0;
}