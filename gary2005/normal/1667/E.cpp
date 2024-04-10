/**
 *    author:  gary
 *    created: 20.04.2022 14:38:49
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+10;
const int MOD=998244353;
const int g=3;
int qmul(int x, int y){return 1ll*x*y-1ll*x*y/MOD*MOD;}
int qadd(int x, int y){return x+y>=MOD?x+y-MOD:x+y;}
int G[21][(1<<20)+1],R[21][(1<<20)+1],inver[(1<<20)+1];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
int len;
int rev[1<<20];
void butterfly(vector<int> & v){
    rep(i,len){
        rev[i]=rev[i>>1]>>1;
        if(i&1) rev[i]|=len>>1; 
    }
    rep(i,len) if(rev[i]>i) swap(v[i],v[rev[i]]);
}
vector<int> ntt(vector<int> v){
    butterfly(v);
    vector<int> nex;
        int lg=1;
    for(  int l=2;l<=len;l<<=1,++lg){
        nex.clear();
        nex.resize(len);
        for(  int j=0;j<len;j+=l){
            for(  int k=0;k<l/2;++k){
                    int A,B;
                A=v[j+k];
                B=v[j+l/2+k];
                B=qmul(B,G[lg][k]);
                nex[j+k]=qadd(A,B);
                nex[j+k+l/2]=qadd(A,MOD-B);
            }
        }
        v=nex;
    }
    return v;
}
vector<int> intt(vector<int> v){
    butterfly(v);
    vector<int> nex;
        int lg=1;
    for(int l=2;l<=len;l<<=1,++lg){
        nex.clear();
        nex.resize(len);
        for(int j=0;j<len;j+=l){
            for(int k=0;k<l/2;++k){
                    int A,B;
                A=v[j+k];
                B=v[j+l/2+k];
                B=qmul(R[lg][k],B);
                nex[j+k]=qadd(A,B);
                nex[j+k+l/2]=qadd(A,MOD-B);
            }
        }
        v=nex;
    }
    return v;
}
void getlen(int x){
    len=1;
    while(len<x){
        len<<=1;
    }
}
vector<int> operator * (vector<int> A,vector<int> B){
    if(A.size()+B.size()<=25){
        vector<int> ret(A.size()+B.size()-1);
        rep(i,A.size()) rep(j,B.size()) ret[i+j]=qadd(ret[i+j],qmul(A[i],B[j]));
        return ret;
    }
    getlen(A.size()+B.size());
    A.resize(len);
    B.resize(len);
    A=ntt(A);
    B=ntt(B);
    rep(i,len) A[i]=qmul(A[i],B[i]);
    A=intt(A);
        int iv=inver[len];
    rep(i,len){
        A[i]=qmul(A[i],iv);
    }
    while(!A.empty()&&A.back()==0) A.pop_back();
    return A;
}
int fact[MAXN],ifact[MAXN],ans[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rb(i,1,(1<<20)) inver[i]=inv(i); 
    rb(i,1,20){
        G[i][0]=1;
        R[i][0]=1;
        int tmp2=inv(quick(g,(MOD-1)>>i)); 
        int tmp=quick(g,(MOD-1)>>i);
        rb(j,1,(1<<i)){
            G[i][j]=qmul(G[i][j-1],tmp);
            R[i][j]=qmul(R[i][j-1],tmp2);
        }
    }
    int n;
    cin>>n;
    fact[0]=1;
    rb(i,1,MAXN-1) fact[i]=1ll*fact[i-1]*i%MOD;
    rb(i,0,MAXN-1) ifact[i]=inv(fact[i]);
    rb(i,1,n) ans[i]=fact[n-1];
    vector<int> f,g;
    f.assign(n+1,0),g.assign(n+1,0);
    rb(i,(n+1)/2,n-1) f[i]=1ll*inv(i)*fact[n-i-1]%MOD;
    rb(i,0,n) g[i]=ifact[i];
    f=f*g;
    rb(i,0,n) f[i]=1ll*f[i]*fact[i]%MOD;
    rb(i,1,n/2) ans[i]=qadd(ans[i],MOD-f[n-i]);
    f.assign(n+1,0),g.assign(n+1,0);
    rb(i,0,n/2-1) f[i]=fact[n-i-2];
    rb(i,0,n) g[i]=ifact[i];
    f=f*g;
    rb(i,0,n) f[i]=1ll*f[i]*fact[i]%MOD;
    rb(i,1,n) ans[i]=qadd(ans[i],MOD-1ll*f[n-i]*(i-1)%MOD);
    rb(i,1,n) cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}