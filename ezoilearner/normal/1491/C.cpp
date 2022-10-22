#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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

int n,q;
#define Maxn 5005
int S[Maxn],B[Maxn];
ll d[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(S[i]),B[i];
		ll res=0;
		rep(i,1,n){
			ll cur=0;
			rep(j,1,i-2)
				if(j+S[j]>=i)cur++;
			d[i]=cur;
			if(i>1){
				d[i]+=d[i-1]-(S[i-1]-1);
			}
			res+=max(0ll,S[i]-1-d[i]);
			if(d[i]<S[i]-1)d[i]=S[i]-1;
		}
		printf("%lld\n",res);
	}
	return 0;
}