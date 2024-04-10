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

typedef long long ll;
int n,m;
#define Maxn 4005
ll a[Maxn];
typedef vector<ll> P;
#define rez resize
const ll inf=1e18;

void cmax(ll &a,ll b){a=max(a,b);}

P run(int l,int r){
	if(l>r){
		P res;res.rez(1);
		res[0]=0ll;
		return res;
	}	
	int p=l;
	rep(i,l+1,r)
		if(a[i]<a[p])p=i;
	P v1=run(l,p-1),v2=run(p+1,r);
	P res;res.rez(r-l+2);
	rep(i,0,r-l+1)res[i]=-inf;
	for(int i=0;i<v1.size();++i)
		for(int j=0;j<v2.size();++j){
			cmax(res[i+j],v1[i]+v2[j]-2ll*i*j*a[p]);
			cmax(res[i+j+1],v1[i]+v2[j]+m*a[p]-((i+j+1)*(i+j+1)-i*i-j*j)*a[p]);
		}
	return res;
}

int main(){
	rd(n);rd(m);
	rep(i,1,n){
		int x;rd(x);
		a[i]=x;
	}
	P z=run(1,n);
	printf("%lld\n",z[m]);
	return 0;
}