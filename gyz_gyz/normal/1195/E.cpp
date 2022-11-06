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
const int N=3e3+10;
const int mo=998244353;
int h[N][N],d[N][N];
void init(int n,int m){int g,x,y,z;
	scanf("%d%d%d%d",&g,&x,&y,&z);
	rep(i,1,n)rep(j,1,m){
		h[i][j]=g;g=(1ll*g*x+y)%z;
	}
}
int main(){int n,m,nn,mm;ll ans=0;
	scanf("%d%d%d%d",&n,&m,&nn,&mm);
	init(n,m);
	rep(i,1,n){
		deque<int>s;
		rep(j,1,mm-1){
			while(!s.empty()&&h[i][s.back()]>=h[i][j])s.pop_back();
			s.pb(j);
		}
		rep(j,mm,m){
			while(!s.empty()&&h[i][s.back()]>=h[i][j])s.pop_back();
			s.pb(j);d[i][j]=h[i][s.front()];
			if(s.front()<=j-mm+1)s.pop_front();
		}
	}
	rep(j,mm,m){
		deque<int>s;
		rep(i,1,nn-1){
			while(!s.empty()&&d[s.back()][j]>=d[i][j])s.pop_back();
			s.pb(i);
		}
		rep(i,nn,n){
			while(!s.empty()&&d[s.back()][j]>=d[i][j])s.pop_back();
			s.pb(i);ans+=d[s.front()][j];
			if(s.front()<=i-nn+1)s.pop_front();
		}
	}
	printf("%lld\n",ans);
}