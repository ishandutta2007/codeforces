#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n;
ll mod;
typedef vector<ll> poly;
const int mb=18;//can change !!!!
ll roots[1<<mb];
int rev[1<<mb];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void operator<<(ostream& out,poly y){
	for(auto c:y) out << c << ' ';
}
poly operator+(poly x,poly y){
	int n=max(x.size(),y.size());
	x.resize(n);y.resize(n);
	for(int i=0; i<n ;i++){
		x[i]+=y[i];
		if(x[i]>=mod) x[i]-=mod;
	}
	return x;
}
poly operator-(poly x,poly y){
	int n=max(x.size(),y.size());
	x.resize(n);y.resize(n);
	for(int i=0; i<n ;i++){
		x[i]+=mod-y[i];
		if(x[i]>=mod) x[i]-=mod;
	}
	return x;
}

void pre(){
	roots[0]=1;
	while(true){
		ll x=rand()%(mod-1)+1;
		ll sex=pw(x,(mod-1)/262144);
		ll ch=pw(sex,1<<17);
		if(ch==1) continue;
		else{
			roots[1]=sex;
			break;
		}
	}
	//roots[1]=pw(15311432,1<<(23-mb));
	for(int i=1; i<(1<<mb) ;i++) roots[i]=roots[i-1]*roots[1]%mod;
}
void fft(poly &p){
	int n=p.size();
	roots[0]=1;
	int m=(1<<mb)/n;
	for(int i=1; i<n ;i++){
		rev[i]=rev[i/2]/2+((i&1)*n/2);
		if(i<rev[i]) swap(p[i],p[rev[i]]);
	}
	for(int k=1; k<n ;k*=2){
        for(int i=0; i<n ;i+=2*k){
            int cur=0,step=n/(2*k);
            for(int j=0; j<k;j++,cur+=step){
                ll x=p[i+j];
                ll y=p[i+j+k]*roots[cur*m]%mod;
                p[i+j]=(x+y>=mod?x+y-mod:x+y);
				p[i+j+k]=(x>=y?x-y:x+mod-y);
            }
        }
    }
}
poly operator*(poly x,poly y){
	int n=1;
	while(n<x.size()+y.size()-1) n*=2;
	x.resize(n,0);y.resize(n,0);
	fft(x);fft(y);
	for(int i=0; i<n ;i++) x[i]=x[i]*y[i]%mod;
	reverse(x.begin()+1,x.end());
	fft(x);
	ll inv=pw(n,mod-2);
	for(int i=0; i<n ;i++) x[i]=x[i]*inv%mod;
	while(x.size()>1 && x.back()==0) x.pop_back();
	return x;
}
ll C[5001][5001];
ll dp[5001][5001];
ll f[5001],inf[5001];
ll g[5001][5001];
ll pb[5001];
ll gg(int x,int y){
	if(x<0 || y<0) return 0;
	else return g[x][y];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> mod;pre();
	C[0][0]=1;
	g[0][0]=1;
	f[0]=1;inf[0]=1;
	pb[0]=1;
	for(int i=1; i<=n ;i++){
		C[i][0]=1;
		f[i]=f[i-1]*i%mod;
		inf[i]=pw(f[i],mod-2);
		pb[i]=pb[i-1]*(n-1)%mod;
		for(int j=1; j<=i ;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			g[i][j]=(gg(i-1,j)*2*j+gg(i-2,j)*2*j*(i-1)+gg(i-1,j+1)*(j+1)*j+gg(i-2,j-1)*(i-1)*2+gg(i-3,j-1)*(i-1)*(i-2))%mod;
			//cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	//cout << roots[1] << endl;
	poly bad(n+1);
	for(int i=0; i<=n ;i++){
		bad[i]=inf[i];
		if(i%2==1) bad[i]=mod-bad[i];
	}/*
	for(int i=0; i<=n ;i++){
		poly sex(n-i+1);
		for(int j=i; j<=n ;j++){
			sex[j-i]=dp[j][j-i]*inf[j]%mod;
		}
		auto funny=bad*sex;
		bad.pop_back();
		//cout << bad[0] << ' ' << bad[1] << ' ' << sex[0] << ' ' << sex[1] << endl;
		for(int j=i; j<=n ;j++){
			g[j][j-i]=funny[j-i]*f[j]%mod;
		}
	}*/
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ll pa=1;
		for(int j=0; j<=i ;j++){//ways to have i chains and j singletons
			ll ways=g[n-j][i-j]*C[n][j]%mod;
			ll love=pa*pb[i-j]%mod;pa=pa*(n-i)%mod;
			//cout << i << ' ' << j << ' ' << ways << ' ' << love << endl;
			ans=(ans+ways*love)%mod;
		}
	}
	cout << ans << '\n';
}