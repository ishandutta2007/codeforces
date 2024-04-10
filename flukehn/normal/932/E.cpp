#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((x).size())
#define ALL(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef unsigned int uint;
typedef unsigned long long uL;
typedef pair<int,int> pii;
typedef vector<int> VI;
template<typename A,typename B>inline bool upmx(A&x,const B&y){return x<y?x=y:1,0;}
template<typename A,typename B>inline bool upmn(A&x,const B&y){return x>y?x=y:1,0;}
const int oo=0x3f3f3f3f,mo=1e9+7;
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#ifdef flukehn
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
#ifndef flukehn
#define debug(...)
#endif
const int N=5011;
int c[N][N],f[N][N];
int inv(int x){
	return Pow(x,mo-2);
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	rep(i,0,k){
		c[i][0]=c[i][i]=1;
		For(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	rep(i,1,k){
		f[i][0]=1;
		rep(j,1,k)f[i][j]=1ll*f[i][j-1]*i%mo;
	}
	//<<"ok"<<endl;
	int ans=0,t=1;
	rep(i,1,min(k,n)){
	//	cerr<<i<<endl;
		t=1ll*t*(n-i+1)%mo*inv(i)%mo;
		int w=0,r=1;
		rep(j,0,i-1){
			w=(w+1ll*r*f[i-j][k]*c[i][j])%mo;
			r=-r;
		}
		//cerr<<i<<" "<<w<<" "<<t<<endl;
		ans=(ans+1ll*w*t%mo*Pow(2,n-i))%mo;
	}
	if(ans<0)ans+=mo;
	cout<<ans<<endl;
}