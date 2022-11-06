#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
const int mx=1000;
int m,sg[2][2][N],v[4];ll a[N];
int cal(ll i,int j,int k){
	return i<mx?sg[j][k][i]:sg[j][k][(i-mx)%m+mx];
}
void sol(){int n,x,y,z;
	scanf("%d%d%d%d",&n,&x,&y,&z);m=mx;
	rep(i,1,m*3)rep(j,0,1)rep(k,0,1){
		rep(l,0,3)v[l]=0;
		v[sg[1][1][max(0,i-x)]]=1;
		if(j)v[sg[0][1][max(0,i-y)]]=1;
		if(k)v[sg[1][0][max(0,i-z)]]=1;
		rep(l,0,3)if(!v[l]){
			sg[j][k][i]=l;break;
		}
	}
	rep(mm,2,m){bool fl=1;
		rep(j,0,1)rep(k,0,1)rep(i,0,m-1)
			if(sg[j][k][m+i]!=sg[j][k][m+mm+i]){
				fl=0;break;
			}
		if(fl){
			m=mm;break;
		}
	}
	int tot=0,ans=0;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		tot^=cal(a[i],1,1);
	}
	rep(i,1,n){
		int np=tot^cal(a[i],1,1);
		if(np==cal(max(a[i]-x,0ll),1,1))++ans;
		if(np==cal(max(a[i]-y,0ll),0,1))++ans;
		if(np==cal(max(a[i]-z,0ll),1,0))++ans;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}