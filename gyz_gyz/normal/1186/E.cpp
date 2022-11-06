#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e3+10;
const int mo=998244353;
ll n,m,a[N][N];
ll sol(ll lx,ll rx,ll ly,ll ry,int x,bool y){
	if(!x){
		ll res=a[rx][ry]-a[lx-1][ry]-a[rx][ly-1]+a[lx-1][ly-1];
		if(y)res=(rx-lx+1)*(ry-ly+1)-res;
		return res;
	}
	if((lx==1&&rx>>x==n)||(ly==1&&ry>>x==m))return (rx-lx+1)*(ry-ly+1)/2;
	ll sn=n<<(x-1),sm=m<<(x-1);
	if(rx<=sn){
		if(ry<=sm)return sol(lx,rx,ly,ry,x-1,y);
		if(ly>sm)return sol(lx,rx,ly-sm,ry-sm,x-1,y^1);
		return sol(lx,rx,ly,sm,x-1,y)+sol(lx,rx,1,ry-sm,x-1,y^1);
	}
	if(lx>sn){
		if(ry<=sm)return sol(lx-sn,rx-sn,ly,ry,x-1,y^1);
		if(ly>sm)return sol(lx-sn,rx-sn,ly-sm,ry-sm,x-1,y);
		return sol(lx-sn,rx-sn,ly,sm,x-1,y^1)+sol(lx-sn,rx-sn,1,ry-sm,x-1,y);
	}
	if(ry<=sm)return sol(lx,sn,ly,ry,x-1,y)+sol(1,rx-sn,ly,ry,x-1,y^1);
	if(ly>sm)return sol(lx,sn,ly-sm,ry-sm,x-1,y^1)+sol(1,rx-sn,ly-sm,ry-sm,x-1,y);
	return sol(lx,sn,ly,sm,x-1,y)+sol(lx,sn,1,ry-sm,x-1,y^1)
	+sol(1,rx-sn,ly,sm,x-1,y^1)+sol(1,rx-sn,1,ry-sm,x-1,y);
}
int main(){int q;
	scanf("%lld%lld%d",&n,&m,&q);
	rep(i,1,n){string s;cin>>s;
		rep(j,1,m)a[i][j]=s[j-1]-'0';
	}
	rep(i,1,n)rep(j,1,m)a[i][j]+=a[i][j-1];
	rep(i,1,n)rep(j,1,m)a[i][j]+=a[i-1][j];
	rep(i,1,q){ll lx,rx,ly,ry;
		scanf("%lld%lld%lld%lld",&lx,&ly,&rx,&ry);
		printf("%lld\n",sol(lx,rx,ly,ry,30,0));
	}
}