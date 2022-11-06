#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

ll cross(ll *a,ll *b) {
	ll s=0;
	rep(i,0,3) s+=a[i]*b[i];
	return s;
}
ll dis(ll *a) { return cross(a,a);}
int p[10][3],q[10][3];
int fg;
bool find(ll *a) {
	rep(i,0,8) {
		if (a[0]==q[i][0]&&a[1]==q[i][1]&&a[2]==q[i][2]) return 1;
	}
	return 0;
}
bool check() {
	ll dx[3],dy[3],dz[3],a[3],b[3],c[3],d[3];
	rep(i,1,8) rep(j,i+1,8) rep(k,j+1,8) {
		rep(l,0,3) dx[l]=q[i][l]-q[0][l];
		rep(l,0,3) dy[l]=q[j][l]-q[0][l];
		rep(l,0,3) dz[l]=q[k][l]-q[0][l];
		if (dis(dx)!=0&&cross(dx,dy)==0&&cross(dx,dz)==0&&cross(dy,dz)==0&&dis(dx)==dis(dy)&&dis(dy)==dis(dz)) {
			rep(l,0,3) a[l]=q[0][l]+dx[l]+dy[l];
			rep(l,0,3) b[l]=q[0][l]+dx[l]+dz[l];
			rep(l,0,3) c[l]=q[0][l]+dy[l]+dz[l];
			rep(l,0,3) d[l]=q[0][l]+dx[l]+dy[l]+dz[l];
			if (find(a)&&find(b)&&find(c)&&find(d)) return 1;
		}
	}
	return 0;
}
void dfs(int u) {
	if (u>=8) {
		if (check()) {
			puts("YES");
			rep(i,0,8) {
				rep(j,0,3) printf("%d ",q[i][j]);
				puts("");
			}
			throw 1;
		}
	} else {
		q[u][0]=p[u][0];q[u][1]=p[u][1];q[u][2]=p[u][2];
		dfs(u+1);
		q[u][0]=p[u][0];q[u][1]=p[u][2];q[u][2]=p[u][1];
		dfs(u+1);
		q[u][0]=p[u][1];q[u][1]=p[u][0];q[u][2]=p[u][2];
		dfs(u+1);
		q[u][0]=p[u][1];q[u][1]=p[u][2];q[u][2]=p[u][0];
		dfs(u+1);
		q[u][0]=p[u][2];q[u][1]=p[u][0];q[u][2]=p[u][1];
		dfs(u+1);
		q[u][0]=p[u][2];q[u][1]=p[u][1];q[u][2]=p[u][0];
		dfs(u+1);
	}
}
int main() {
	rep(i,0,8) rep(j,0,3) scanf("%d",&p[i][j]);
	rep(i,0,3) q[0][i]=p[0][i];
	try {
		dfs(1);
	} catch(int e) {
		fg=1;
	}
	if (!fg) puts("NO");
}