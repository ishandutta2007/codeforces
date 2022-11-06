#include<bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr << #x << " = " << x << std::endl
#define FOR(i,s,t) for(int i=s;i<=t;i++)
#define FEO(x) {freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);}
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e6+11,M=1e6,mod=1e9+7;
int n,c[N];
bool np[N];
int mu[N],p[N],tot;
void init(){
	mu[1]=1;
	for(int i=2;i<=M;i++){
		if(!np[i])p[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*p[j]<=M;j++){
			np[i*p[j]]=1;
			if(i%p[j])mu[i*p[j]]=-mu[i];
			else {
				mu[i*p[j]]=0;
				break;
			}
		}
	}
}
int pow(int n,int m){
	int ret=1;
	for(;m;m>>=1,n=1LL*n*n%mod)
		if(m&1)ret=1LL*ret*n%mod;
	return ret;
}
void add(int x){
	for(int i=1;i*i<=x;i++)
		if(x%i==0) {
			c[i]++;
			if(i!=x/i)c[x/i]++;
		}
} 
int A[N];
int main(){
	init();
	n=rd();
	for(int i=1;i<=n;i++){
		int x=rd();
		add(x);
	}
	for(int i=2;i<=M;i++){
		if(c[i]) {
			A[i] = 1LL*c[i]*pow(2, c[i]-1)%mod;
		}
	}
	int ans=0;
	for(int i=2;i<=M;i++){
		for(int j=2;i*j<=M;j++){
			A[i] += mu[j] * A[i*j];
			A[i] = (A[i]%mod + mod) % mod;
		}
		ans=(ans+1LL*A[i]*i)%mod;
	}
	cout << ans << endl;
}