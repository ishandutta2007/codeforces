/**
 *    author:  gary
 *    created: 05.11.2021 20:43:34
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
bool vis[1000000+1];
bool cmp(pair<mp,int> A,pair<mp,int> B){
    return A.FIR.SEC>B.FIR.SEC;
}
pair<int,string> solve(vector<vector<mp> > mat,vector<mp> L_,vector<mp> R_){
    if(mat[0].size()<=1) return II(-1,"fuck");
    
    // rep(i,mat.size()){
    //     rep(j,mat[i].size()){
    //         cout<<"["<<mat[i][j].FIR<<","<<mat[i][j].SEC<<"]"<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<mat[0].size()<<endl;
    int mid=mat[0].size()/2;
    vector<mp> Lp,Rp;
    rep(i,mat.size()){
        mp rng=L_[i];
        rep(j,mid){
            check_max(rng.SEC,mat[i][j].SEC);
            check_min(rng.FIR,mat[i][j].FIR);
        }
        Lp.PB(rng);
        rng=R_[i];
        rb(j,mid,mat[0].size()-1){
            check_max(rng.SEC,mat[i][j].SEC);
            check_min(rng.FIR,mat[i][j].FIR);
        }
        Rp.PB(rng);
    }
    vector<vector<mp> > Nl,Nr;
    Nl.resize(mat.size());
    Nr.resize(mat.size());
    rep(i,mat.size()){
        rb(j,mid,mat[0].size()-1) Nr[i].PB(mat[i][j]);
        rep(j,mid) Nl[i].PB(mat[i][j]);
    }
    // cout<<mat[0].size()<<" "<<mid<<"__"<<endl;
    auto it=solve(Nl,L_,Rp);
    if(it.FIR!=-1) return it;
    it=solve(Nr,Lp,R_);
    if(it.FIR!=-1) {
        it.FIR+=mid;
        return it;
    }
    vector<pair<mp,int> > L,R;
    rep(i,Lp.size()) L.PB(II(Lp[i],i));
    rep(i,Rp.size()) R.PB(II(Rp[i],i));
    sort(ALL(L));
    sort(ALL(R),cmp);
    int i=0;
    int nr=-INF;
    int j=0;
    int cnt=0;
    int nl=INF;
    fill(vis,vis+mat.size(),0);
    while(i<mat.size()){
        nr=max(nr,L[i].FIR.SEC);
        cnt+=vis[L[i].SEC];
        vis[L[i].SEC]=1;
        i++;
        while(i<mat.size()&&L[i].FIR.FIR<=nr){
            nr=max(nr,L[i].FIR.SEC);
            cnt+=vis[L[i].SEC];
            vis[L[i].SEC]=1;
            i++;
        }
        if(i==mat.size()) break;
        while(cnt<i){
            // cout<<j<<' '<<cnt<<' '<<i<<" "<<j<<" "<<R.size()<<endl;
            check_min(nl,R[j].FIR.FIR);
            cnt+=vis[R[j].SEC];
            vis[R[j].SEC]=1;
            j++;
        }
        if(j==i&&R[j].FIR.SEC<nl){
            string s;
            s.resize(mat.size());
            rep(i,mat.size()) if(vis[i]) s[i]='B';
            else s[i]='R';
            return II(mid,s);
        }
    }
    return II(-1,"fuck");
}
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<mp> > mat; 
    mat.resize(n);
    rep(i,n) mat[i].resize(m);
    vector<mp> L,R;
    rep(i,n) rep(j,m){
        int ai;
        scanf("%d",&ai);
        mat[i][j]=II(ai,ai);
    }
    rep(i,n) L.PB(II(INF,-INF));
    R=L;
    auto rest=solve(mat,L,R);
    if(rest.FIR==-1){
        puts("NO");
        return ;
    }
    puts("YES");
    cout<<rest.SEC<<" "<<rest.FIR<<endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}