#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
const ll mod = 1000000007;
ll dp[2005][2005][2];
int n,m;
char s[2005][2005];
struct BIT{
	ll x[2005];
	void init(){ memset(x,0,sizeof(x)); }
	void add(int i,ll s){
		i++;
		for(;i<2005;i+=i&-i) { x[i]+=s; if(x[i] >= mod) x[i] -= mod; }
	}
	ll sum(int i){
		i++;
		ll r = 0;
		for(;i;i-=i&-i) r += x[i];
		return r%mod;
	}
}tate[2005],yoko[2005];
int ruiy[2005][2005],ruit[2005][2005];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%s",&s[i]);
	if(n == 1 && m == 1){ puts("1"); return 0; }
	rep(i,2005) tate[i].init();
	rep(i,2005) yoko[i].init();
	rep(i,n) for(int j=m-1;j>=0;j--){
		ruiy[i][j] = ruiy[i][j+1] + (s[i][j] == '.');
	}
	rep(j,m) for(int i=n-1;i>=0;i--){
		ruit[i][j] = ruit[i+1][j] + (s[i][j] == '.');
	}
	
	tate[0].add(0,1);tate[0].add(1,mod-1);
	yoko[0].add(0,1);yoko[0].add(1,mod-1);
	rep(i,n) rep(j,m){
		ll cur_tate = tate[j].sum(i);
		//i,j+1 ~ i,m-1
		int zany = ruiy[i][j+1];
		yoko[i].add(j+1,cur_tate);
		yoko[i].add(j+zany+1,(mod-cur_tate)%mod);
		ll cur_yoko = yoko[i].sum(j);
		//i+1,j ~ n-1,j
		int zant = ruit[i+1][j]; //if(i>= 1 && j == 3) cout<<i<<j<<zant<<endl;
		tate[j].add(i+1,cur_yoko);
		tate[j].add(i+zant+1,(mod-cur_yoko)%mod);
		//cout<<i<<j<<cur_tate<<cur_yoko<<endl;
		if(i==n-1 && j==m-1) cout << ((cur_tate+cur_yoko)%mod+mod)%mod << endl;
	}
}