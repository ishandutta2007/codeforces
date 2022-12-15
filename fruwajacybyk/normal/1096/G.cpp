#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb() fflush(stdout);

using namespace std;
const int max_n = 1e6 + 5;

#define rep(i,x,y) for(int i=x;i<=y;++i)

typedef long long int ll;
typedef long long LL;

const int mod=998244353 ;

/*
*	Following parts are NTT (Number theoritic transform) code belonging to Hengjie zhang, (zhj on codeforces)
*	His profile link is codeforces.com/profile/zhj.
*	His submission from which code is taken is http://codeforces.com/contest/438/submission/8172645
*	It is recursive implementation of NTT, I think using non - recursive implementation would be even faster. 
*	You can see code of Anton Lunyov for a faster implementation of DFT (NTT).
*/

const ll modulo = 998244353;
int Mod=998244353;
const int alp=3;
const int MAX=(1<<21)+5;
const int mod1=998244353 ;
const int mod2=1300234241;

ll powmod(ll a,ll b,ll m){
  ll res=1%m;
  while(b){
    if(b&1)res=(res*a)%m;
    a=(a*a)%m;
    b>>=1;
  }
  return res;
}

ll mulmod(ll a,ll b,ll m){
  ll res=0;
  while(b){
    if(b&1)res=(res+a)%m;
    a=(a+a)%m;
    b>>=1;
  }
  return res;
}

int MULTIPLICATION_COUNT = 0;
int MAXDEG = 0;

/* code is taken from internet, I will write my fft code later */
const int mo=998244353;
const int maxS = 1<<21;
int W[2][maxS+10],pos[22][maxS+10],tmp[maxS+10],c[maxS+10],b[maxS+10];;
int n,m;
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*x*res%mo;
		x=1ll*x*x%mo;
		y/=2;
	}
	return res;
}
void prep(){
	int g=3,x=1;
	g=Pow(g,(mo-1)/maxS);
	rep(i,0,maxS-1){
		W[0][i]=x;
		x=1ll*x*g%mo;
	}
	rep(i,0,maxS-1)W[1][i]=W[0][(maxS-i)%maxS];
	
	rep(i,0,21)
		rep(j,0,(1<<i)-1){
			int x=0;
			rep(k,0,i-1)if((j>>k)&1)x|=1<<i-1-k;
			pos[i][j]=x;
		}
}
void DFT(int *a,int flag,int s,int cnt){
	rep(i,0,s-1)if(pos[cnt][i]>i)swap(a[i],a[pos[cnt][i]]);
	for(int i=1;i<s;i<<=1)
		for(int j=0;j<s;j+=i<<1)
			for(int k=0;k<i;++k){
				int u=a[j+k],v=1ll*a[j+k+i]*W[flag][k*(maxS/i/2)]%mo;
				a[j+k]=(u+v)%mo;
				a[j+k+i]=(u-v+mo)%mo;
			}
	if(flag){
		int ni=Pow(s,mo-2);
		rep(i,0,s-1)a[i]=1ll*a[i]*ni%mo;
	}
}
void NTT(int *p1,int l1,int *p2,int l2,int *a){	
	MULTIPLICATION_COUNT++;
	int maxx=max(l1,l2),s=1,cnt=0;
	while(s<maxx)s<<=1,cnt++;
	s<<=1; cnt++;
	for(int i=0;i<s;++i){
		if(i<l2)b[i]=*(p2+i);
		else b[i]=0;
	}
	for(int i=0;i<s;++i){
		if(i<l1)a[i]=*(p1+i);
		else a[i]=0;
	}
	DFT(a,0,s,cnt);
	DFT(b,0,s,cnt);
	rep(i,0,s-1)a[i]=1ll*a[i]*b[i]%mo;
	DFT(a,1,s,cnt);
}
// NTT Code ends.
int dupa1[max_n], dupa2[max_n], dupa3[max_n];

VI mnoz(VI& v1, VI& v2) {
	int n1 = v1.size();
	int n2 = v2.size();
	FOR(i,0,n1) dupa1[i] = v1[i];
	FOR(i,0,n2) dupa2[i] = v2[i];
	NTT(dupa1, n1, dupa2, n2, dupa3);
	VI ans;
	FOR(i,0,n1+n2-1) ans.pb(dupa3[i]);
	return ans;
}


VI rower(VI v, int m) {
    VI res; res.pb(1);
    while (m) {
        if (m&1) {
            res = mnoz(res, v);
        }
        m = m / 2;
        v = mnoz(v, v);
    }
    return res;
}




int main() {
	prep();
    make2(n, k);
    makev(digi, k);
    VI kij;
    FOR(i,0,10) kij.pb(0);
    FORE(i, digi) kij[*i] = 1;
    VI haha = rower(kij, n/2);
    int ans = 0;
    FOR(i,0,haha.size()) {
        int co = haha[i];
        ans += (co * 1LL * co) % mod;
        ans %= mod;
    }
    printf("%d\n", ans);
}