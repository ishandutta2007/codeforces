/**
 *    author:  gary
 *    created: 06.09.2022 17:04:03
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
namespace combination
{
    const int MOD=1e9+7;
    const int MAXN=200000;
    int fact[MAXN+1],ifact[MAXN+1];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
    }
    int comb(int A,int B){
        if(A<0||B<0) return 0;
        if(A<B) return 0;
        return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
} // namespace combination
using namespace combination;
int n,m,p,k,d[MAXN],Fl[1505][1505],Fr[1505][1505],Sl[MAXN],Sr[MAXN],Tl[MAXN],Tr[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    cin>>a>>b;p=1ll*a*inv(b)%MOD;
    cin>>k;
    genmath();
    rb(i,0,min(m,k)){
        d[i]=1ll*comb(k,i)*quick(p,i)%MOD*quick((MOD+1-p),k-i)%MOD;
    }
    // rb(i,1,m) add(d[i],d[i-1]);
    rb(i,1,m) rb(j,i,m) add(Sl[j],1ll*d[i-1]*d[m-j]%MOD),add(Sr[i],1ll*d[i-1]*d[m-j]%MOD);
    rb(i,1,m) add(Sl[i],Sl[i-1]);
    rl(i,m,1) add(Sr[i],Sr[i+1]);
    Fl[0][m]=Fr[0][1]=1;
    rb(i,1,n){
        rb(j,1,m){
            Fl[i][j]=1ll*Fl[i-1][m]*Sl[j]%MOD;
            Fr[i][j]=1ll*Fl[i-1][m]*Sr[j]%MOD;
        }
        int sum=0;
        rb(j,1,m){
            Tl[j]=1ll*(Sl[j]-Sl[j-1]+MOD)*Fr[i-1][j+1]%MOD;
            add(sum,1ll*Fl[i-1][j-1]*d[j-1]%MOD);
            add(Tl[j],1ll*sum*d[m-j]%MOD);
        }
        sum=0;
        rl(j,m,1){
            Tr[j]=1ll*(Sr[j]-Sr[j+1]+MOD)*Fl[i-1][j-1]%MOD;
            add(sum,1ll*Fr[i-1][j+1]*d[m-j]%MOD);
            add(Tr[j],1ll*sum*d[j-1]%MOD);
        }
        rb(j,1,m) add(Tl[j],Tl[j-1]);
        rl(j,m,1) add(Tr[j],Tr[j+1]);
        rb(j,1,m){
            sub(Fl[i][j],Tl[j]);
            sub(Fr[i][j],Tr[j]);
        }
        // cout<<Fl[i][m]<<Sl[m]<<endl;
    }
    cout<<Fl[n][m]<<'\n';
    return 0;
}