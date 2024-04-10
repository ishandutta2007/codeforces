#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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

int m,K;
#define Maxn 1005
int a[Maxn][Maxn],sum[Maxn],at;
ll b[Maxn];

int main(){
	rd(m);rd(K);
	rep(i,0,K-1){
		rep(j,1,m){
			rd(a[i][j]);
			sum[i]+=a[i][j];
			b[i]+=1ll*a[i][j]*a[i][j];
		}
	}
	int S=(sum[K-1]-sum[0])/(K-1);
	rep(i,1,K-2)
		if(sum[i]!=sum[0]+i*S){
			at=i;
			break;
		}
	ll z;
	if(at>2)z=b[0]+b[2]-2*b[1];
	else z=b[K-1]+b[K-3]-2*b[K-2];
	int to=sum[0]+at*S-sum[at];
	rep(j,1,m){
		ll cur=b[at]-1ll*a[at][j]*a[at][j]+1ll*(a[at][j]+to)*(a[at][j]+to);
		if(b[at-1]+b[at+1]-2*cur==z){
			printf("%d %d\n",at,a[at][j]+to);
			break;
		}
	}
	return 0;
}