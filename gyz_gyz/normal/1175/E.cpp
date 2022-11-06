#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int f[18][N],r[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,500000)r[i]=i;
	rep(i,1,n){int x,y;
		scanf("%d%d",&x,&y);
		r[x]=max(r[x],y);
	}int nw=0;
	rep(i,0,500000){
		nw=max(nw,r[i]);
		f[0][i]=nw;
	}
	rep(i,1,17)rep(j,0,500000)f[i][j]=f[i-1][f[i-1][j]];
	while(m--){int l,r,ans=0;
		scanf("%d%d",&l,&r);
		dep(i,17,0)if(f[i][l]<r)l=f[i][l],ans+=1<<i;
		l=f[0][l];++ans;
		printf("%d\n",l<r?-1:ans);
	}
}