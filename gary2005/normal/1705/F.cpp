/**
 *    author:  gary
 *    created: 15.07.2022 22:13:07
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
int all_t;
int n;
int query_f(vector<int> v){
    string str;
    rb(i,1,n) str.push_back('T');
    for(auto it:v) str[it-1]='F';
    cout<<str<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    if(x==n){
        exit(0);
    }
    x-=all_t;
    x=v.size()+x;
    return x>>1;
}
string ans;
const int B=12;
SRAND;
int canmask[1<<B],siz=0,pp[1<<B];
void solve(vector<int> v,int cntf){
    siz=0;
    rep(mask,1<<v.size())
    if(__builtin_popcount(mask)==cntf)
    canmask[siz++]=mask;
    while (siz>1){
        pair<double,int> best;
        best=II(-1e18,-INF);
        rep(mask,1<<v.size()){
            if(mask+1==(1<<v.size())) continue;
            if(!mask) continue;
            double p[B+1];
            rep(i,B+1) p[i]=0;
            rep(j,siz) p[pp[canmask[j]&mask]]++;
            int z=pp[mask];
            rep(j,z+1) p[j]/=siz;
            double H=0;
            rep(j,z+1) if(p[j]) H+=-p[j]*log2(p[j]);
            check_max(best,II(H,mask));
        }
        vector<int> v2;
        rep(i,v.size()) if((best.second>>i)&1) v2.push_back(v[i]);
        int y=query_f(v2);
        int newsiz=0;
        rep(j,siz) if(pp[canmask[j]&best.second]==y) canmask[newsiz++]=canmask[j];
        siz=newsiz;
    }
    rep(j,v.size()) if((canmask[0]>>j)&1) ans[v[j]-1]='F';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(j,1<<B) pp[j]=__builtin_popcount(j);
    cin>>n;
    string str;
    rb(i,1,n) str.push_back('T');
    cout<<str<<endl;
    fflush(stdout);
    cin>>all_t;
    ans=str;
    vector<int> v;
    rb(i,1,n) {
        v.push_back(i);
        if(v.size()==B||i==n){
            shuffle(ALL(v),rng);
            solve(v,query_f(v));
            v.clear();
        }
    }
    cout<<ans<<endl;
    fflush(stdout);
    return 0;
}