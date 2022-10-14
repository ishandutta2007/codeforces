/**
 *    author:  gary
 *    created: 25.02.2022 12:57:18
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
const int MOD=998244353;
const int g=3;
    int qmul(int x, int y){return 1ll*x*y-1ll*x*y/MOD*MOD;}
    int qadd(int x, int y){return x+y>=MOD?x+y-MOD:x+y;}
int G[21][(1<<20)+1],R[21][(1<<20)+1],inver[(1<<20)+1];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
struct POLY{
    int len;
    int rev[1<<20];
    POLY(){
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
    }
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
    vector<int> mul(vector<int> A,vector<int> B){
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
    vector<int> inverse(vector<int> A,int n){
        //% x^n 
        vector<int> ret(n);
        if(n==1){
            ret[0]=quick(A[0],MOD-2);
        }
        else{
            vector<int> oth=inverse(A,(n+1)>>1);
            ret=oth;
            ret.resize(n);
            rep(i,n) ret[i]=(ret[i]+ret[i])%MOD;
            getlen((oth.size()<<1)+A.size());
            oth.resize(len);
            A.resize(len);
            oth=ntt(oth);
            A=ntt(A);
            rep(i,len) oth[i]=qmul(qmul(oth[i],oth[i]),A[i]);
            oth=intt(oth);
            oth.resize(n);
                int iv=inver[len];
            rep(i,n){
                oth[i]=qmul(oth[i],iv);
            }
            rep(i,n) ret[i]=qadd(ret[i],MOD-oth[i]);
        }
        return ret;
    }
}poly;
vector<int> operator * (vector<int> A,vector<int> B){
    return poly.mul(A,B);
}
int n,m;
int a[100000+20];
int c[100000+20];
bool b[100000+20];
int pre[100000+20],preidx[100000+20];
int pw2[100000+20];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A-=B;
    if(A<0) A+=MOD;
}
int answer2=0;
int ivpw2[100000+20];
void solve(int l,int r){
    if(l>=r) return;
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    vector<int> L(mid-l+1,0),R(r-mid,0);
    int D=l+mid+1;
    rb(i,l,mid) if(b[i]) L[i-l]=pw2[c[i]];
    rb(i,mid+1,r) if(b[i]) R[i-mid-1]=ivpw2[c[i]];
    auto A=L*R;
    if(A.size())
    rb(iaj,0,A.size()-1){
        int mid=(iaj+D)>>1;
        add(answer2,2ll*A[iaj]*preidx[mid]%MOD);
    }
    rb(i,l,mid) if(b[i]) L[i-l]=pw2[c[i]];
    rb(i,mid+1,r) if(b[i]) R[i-mid-1]=1ll*i*ivpw2[c[i]]%MOD;
    A=L*R;
    if(A.size())
    rb(iaj,0,A.size()-1){
        int mid=(iaj+D)>>1;
        sub(answer2,1ll*A[iaj]*pre[mid]%MOD);
    }
    rb(i,l,mid) if(b[i]) L[i-l]=1ll*i*pw2[c[i]]%MOD;
    rb(i,mid+1,r) if(b[i]) R[i-mid-1]=ivpw2[c[i]];
    A=L*R;
    if(A.size())
    rb(iaj,0,A.size()-1){
        int mid=(iaj+D)>>1;
        sub(answer2,1ll*A[iaj]*pre[mid]%MOD);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) cin>>a[i],pre[i]=pre[i-1]+a[i],preidx[i]=preidx[i-1]+1ll*a[i]*i%MOD,pre[i]%=MOD,preidx[i]%=MOD;
    rb(i,1,m){
        int u;
        cin>>u;
        b[u]=1;
        c[u]=1;
    }
    rb(i,1,n) c[i]+=c[i-1];
    pw2[0]=1;
    rb(i,1,n) pw2[i]=(pw2[i-1]<<1)%MOD;
    rb(i,0,n) ivpw2[i]=inv(pw2[i]);
    int answer=0;
    rb(i,1,n) if(b[i]){
        add(answer,1ll*(1ll*i*pre[i]%MOD-preidx[i]+MOD)*pw2[m-c[i]]%MOD);
    }
    rb(i,1,n) if(b[i]){
        add(answer,(1ll*preidx[n]-preidx[i-1]+MOD-1ll*i*(pre[n]-pre[i-1]+MOD)%MOD+MOD)*pw2[c[i]-1]%MOD);
    }
    int tmp=0;
    rb(i,1,n){
        if(b[i]){
            int iv2=inv(pw2[c[i]]);
            add(answer2,1ll*iv2*i%MOD*pre[i]%MOD*tmp%MOD);
            sub(answer2,1ll*iv2*tmp%MOD*preidx[i]%MOD);
            add(tmp,pw2[c[i]]);
        }
    }
    tmp=0;
    rl(j,n,1){
        if(b[j]){
            add(answer2,1ll*pw2[c[j]]*tmp%MOD*j%MOD*pre[j-1]%MOD);
            sub(answer2,1ll*pw2[c[j]]*tmp%MOD*preidx[j-1]%MOD);
            add(tmp,inv(pw2[c[j]]));
        }
    }
    solve(1,n);
    add(answer,1ll*quick(2,m-1)*answer2%MOD);
    cout<<1ll*answer*inv(quick(2,m)-1)%MOD<<endl;
    return 0;
}