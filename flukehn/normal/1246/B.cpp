#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef vector<int> VI;
typedef pair<int,int> pa;
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N=1e5,m1=1e9+7,m2=1e9+9;
int a[N+11],n,k;
L ans;
int u;
L v;
void gao(int o){
	u=v=1;
	int x,y;
	for(int i=2;i*i<=o;++i){
		if(o%i==0){
			y=0;
			while(o%i==0)++y,o/=i;
			y%=k;
			if(!y)continue;
			rep(j,1,y)u*=i;
			rep(j,1,k-y){
				v*=i;
				if(v>N)return;
			}
		}
	}
	u*=o;
	rep(j,1,k-1){
		v*=o;
		if(v>N)return;
	}
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	cin>>n>>k;
	int x,y;
	rep(i,1,n){
		cin>>x;
		gao(x);
		if(v<=N)ans+=a[v];
		++a[u];
	}
	
	cout<<ans<<endl;
}