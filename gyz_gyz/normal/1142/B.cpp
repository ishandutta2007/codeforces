#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
int n,m,q,a[N],t[N],f[N],fr[N],v[N];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n){
		scanf("%d",&a[i]);
		t[a[i]]=i;
	}
	rep(i,1,m){int x;
		scanf("%d",&x);f[i]=i;
		fr[i]=v[a[(t[x]+n-2)%n+1]];
		v[x]=i;
	}
	for(int x=n-1;x;x>>=1){
		if(x&1)rep(i,1,m)f[i]=fr[f[i]];
		dep(i,m,1)fr[i]=fr[fr[i]];
	}
	rep(i,1,m)f[i]=max(f[i],f[i-1]);
	rep(i,1,q){int l,r;
		scanf("%d%d",&l,&r);
		printf("%d",f[r]>=l?1:0);
	}
}