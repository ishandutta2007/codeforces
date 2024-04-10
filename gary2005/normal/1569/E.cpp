/**
 *    author:  gary
 *    created: 08.09.2021 22:33:10
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
const int MAXN=1<<5;
const int MOD=998244353;
int pw[MAXN+1],p[MAXN+1];
vector<int> mv(vector<int> T,int mask){
    vector<int> Z;
    rep(i,T.size()/2){
        int A,B;
        A=i*2;
        B=i*2+1;
        if((mask>>i)&1) Z.PB(T[A]),p[T[B]]=T.size()+1;
        else Z.PB(T[B]),p[T[A]]=T.size()+1;
    }
    return Z;
}
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    int k,a,h,n;
    cin>>k>>a>>h;
    n=1<<k;
    a%=MOD;
    pw[0]=1;
    rb(i,1,n){
        pw[i]=1ll*pw[i-1]*a%MOD;
    }
    vector<pair<int,vector<int> > > A_;
    map<mp,vector<int> > B_;
    int ha=n/2;
    rep(mask,1<<(ha-1)){
        vector<int> A,B;
        rb(i,1,n/2) A.PB(i),p[i]=2;
        rb(i,n/2+1,n) B.PB(i),p[i]=2;
        int ma=mask;
        while(A.size()>1){
            A=mv(A,ma);
            B=mv(B,ma);
            ma>>=A.size();
        }
        int val=0;
        rb(i,1,n/2){
            add(val,1ll*i*pw[p[i]]%MOD);
        }
        vector<int> ap,bp;
        rb(i,1,n/2) ap.PB(p[i]);
        rb(i,n/2+1,n) bp.PB(p[i]);
        A_.PB(II(val,ap));
        // for(auto it:ap){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        val=0;
        rb(i,n/2+1,n){
            add(val,1ll*i*pw[p[i]]%MOD);
        }
        B_[II(val,B[0])]=bp;
    }
    rb(i,1,n){
        int H=h;
        add(H,1ll*i*pw[2]%MOD);
        add(H,MOD-1ll*i*pw[1]%MOD);
        H%=MOD;
        for(auto it:A_){
            int ANO=H;
            add(ANO,MOD-it.FIR);
            if(i<=n/2&&it.SEC[i-1]!=2) continue;
            rb(z,n/2+1,n){
                if(i>n/2&&i!=z){
                    continue;
                } 
                if(B_.find(II(ANO,z))!=B_.end()){
                    vector<int> ans;
                    for(auto itt:it.SEC) ans.PB(itt);
                    for(auto itt:B_[II(ANO,z)]) ans.PB(itt);
                    ans[i-1]=1;
                    for(auto it:ans){
                        printf("%d ",it);
                    }
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}