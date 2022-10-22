#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n;
#define Maxn 400010
int a[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		a[n+1]=0;
		ll res=0;
		rep(i,1,n)
			if(a[i]>max(a[i-1],a[i+1])){
				res+=a[i]-max(a[i-1],a[i+1]);
				a[i]=max(a[i-1],a[i+1]);
			}
		rep(i,1,n+1)res+=abs(a[i]-a[i-1]);
		printf("%lld\n",res);
	}
	return 0;
}