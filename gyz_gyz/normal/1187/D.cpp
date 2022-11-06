#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=1e9+7;
int s[N],a[N],b[N],ct[N];
int q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return s[x];int m=(L+R)>>1;
	if(r<=m)return q(x<<1,l,r,L,m);
	if(l>m)return q(x<<1|1,l,r,m+1,R);
	return min(q(x<<1,l,m,L,m),q(x<<1|1,m+1,r,m+1,R));
}
void f(int x,int y,int z,int L,int R){
	if(L==R){s[x]=z;return;}int m=(L+R)>>1;
	if(y<=m)f(x<<1,y,z,L,m);
	else f(x<<1|1,y,z,m+1,R);
	s[x]=min(s[x<<1],s[x<<1|1]);
}
void sol(){int n;
	scanf("%d",&n);map<pii,int>p;
	rep(i,1,n)ct[i]=0;
	rep(i,1,n){
		scanf("%d",&a[i]);
		p[{a[i],++ct[a[i]]}]=i;
	}
	rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,n)--ct[b[i]];
	rep(i,1,n)if(ct[i]){
		printf("NO\n");return;
	}
	rep(i,1,n)f(1,i,a[i],1,n);
	rep(i,1,n){
		int t=p[{b[i],++ct[b[i]]}];
		if(q(1,1,t,1,n)<b[i]){
			printf("NO\n");return;
		}
		f(1,t,n+1,1,n);
	}
	printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}