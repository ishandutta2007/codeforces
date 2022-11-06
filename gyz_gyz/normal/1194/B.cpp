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
const int N=2e5+10;
const int mo=1e9+7;
string s[N];int dx[N],dy[N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n-1)cin>>s[i];
	rep(i,0,n-1){dx[i]=0;
		rep(j,0,m-1)if(s[i][j]=='.')++dx[i];
	}
	rep(i,0,m-1){dy[i]=0;
		rep(j,0,n-1)if(s[j][i]=='.')++dy[i];
	}int ans=n*m;
	rep(i,0,n-1)rep(j,0,m-1)ans=min(ans,dx[i]+dy[j]-(s[i][j]=='.'));
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}