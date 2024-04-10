#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 300010
#define cout cerr
#define FR first
#define SE second
int c[Maxn],K[Maxn];
ll s[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
} 

int main(){
	int T;
	rd(T);
	while(T--){
		ll sum=0,res;
		rd(n);rd(m);
		rep(i,1,n)rd(K[i]);
		sort(K+1,K+n+1);
		rep(i,1,m)rd(c[i]),s[i]=s[i-1]+c[i];rep(i,1,n)sum+=c[K[i]];res=sum;
		int at=0,mn=1000000000;
		per(i,n,1){
			if(n-i+1>m)break;
			mn=min(mn-1,K[i]-1);
			sum-=c[K[i]];
			if(mn>=0)res=min(res,s[n-i+1]+sum);
		}
		printf("%lld\n",res);
	}
	return 0;
}