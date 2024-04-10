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

L n,p;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	while(cin>>n>>p){
		int i;
		for(i=1;i<33333;++i){
			L m=n-i*p;
			if(m<=0||i>m)continue;
			if(__builtin_popcountll(m)<=i)break;
		}
		if(i<33333)cout<<i<<endl;
		else cout<<-1<<endl;
	}
}