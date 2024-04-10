#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll mod2=1e9+7;
#define fi first
#define se second
int n,k;
struct mat{
	ll a[2][2];
	ll b[2][2];
};
mat operator*(mat x,mat y){
	mat z;
	for(int i=0; i<2 ;i++){
		for(int j=0; j<2 ;j++){
			z.a[i][j]=0;
			for(int k=0; k<2 ;k++){
				z.a[i][j]+=x.a[i][k]*y.a[k][j];
			}
			z.a[i][j]%=mod;
		}
	}
	for(int i=0; i<2 ;i++){
		for(int j=0; j<2 ;j++){
			z.b[i][j]=0;
			for(int k=0; k<2 ;k++){
				z.b[i][j]+=x.b[i][k]*y.b[k][j];
			}
			z.b[i][j]%=mod2;
		}
	}
	return z;
}
ll w,t,r,s;
ll hsh(mat x){
	return (w*x.a[0][0]+t*x.a[0][1]+r*x.a[1][0]+s*x.a[1][1])%mod*mod2+(w*x.b[0][0]+t*x.b[0][1]+r*x.b[1][0]+s*x.b[1][1])%mod2;
}
mat m[300001];
mat p[300001];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
unordered_map<ll,int>um;
ll pw(ll x,ll y,ll z){
	if(y==0) return 1;
	if(y%2) return pw(x,y-1,z)*x%z;
	ll res=pw(x,y/2,z);
	return res*res%z;
}
void out(mat x){
	cout << x.a[0][0] << ' ' << x.a[0][1] << ' ' << x.a[1][0] << ' ' << x.a[1][1] << endl;
	cout << x.b[0][0] << ' ' << x.b[0][1] << ' ' << x.b[1][0] << ' ' << x.b[1][1] << endl;
}
void solve(){
	um.clear();
	cin >> n;
	ll ans=0;
	p[0].a[0][0]=p[0].a[1][1]=1;p[0].a[0][1]=p[0].a[1][0]=0;
	p[0].b[0][0]=p[0].b[1][1]=1;p[0].b[0][1]=p[0].b[1][0]=0;
	um[hsh(p[0])]++;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		p[i]=p[i-1]*m[x];
		//out(p[i]);
		ans+=um[hsh(p[i])]++;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	w=uniform_int_distribution<int>(0,mod-1)(rng);
	t=uniform_int_distribution<int>(0,mod-1)(rng);
	r=uniform_int_distribution<int>(0,mod-1)(rng);
	s=uniform_int_distribution<int>(0,mod-1)(rng);
	for(int i=1; i<=300000 ;i++){
		ll a=uniform_int_distribution<int>(0,mod-1)(rng);
		ll b=uniform_int_distribution<int>(0,mod-1)(rng);
		ll c=((1-a*a)%mod+mod)%mod*pw(b,mod-2,mod)%mod;
		m[i].a[0][0]=a;m[i].a[0][1]=b;m[i].a[1][0]=c;m[i].a[1][1]=mod-a;
		a=uniform_int_distribution<int>(0,mod2-1)(rng);
		b=uniform_int_distribution<int>(0,mod2-1)(rng);
		c=((1-a*a)%mod2+mod2)%mod2*pw(b,mod2-2,mod2)%mod2;
		m[i].b[0][0]=a;m[i].b[0][1]=b;m[i].b[1][0]=c;m[i].b[1][1]=mod2-a;
		//out(m[i]);
		//out(m[i]*m[i]);
	}
	int q;cin >> q;while(q--) solve();
}