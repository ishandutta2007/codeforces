/**
 *    author:  gary
 *    created: 20.03.2022 23:23:51
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
int solve(vector<int> v){
    if(v.size()==1) return 0;
    int maskl,maskr;
    {
        vector<pair<mp,int> > nw;
        for(int i=0;i<v.size();i++){
            nw.PB(II(II(v[i],v[i+1]),i/2));
            i++;
        }
        sort(ALL(nw));
        vector<int> nwv(v.size()/2);
        int cnt=0;
        rep(i,nw.size()){
            if(i&&nw[i].first!=nw[i-1].first) cnt++;
            nwv[nw[i].second]=cnt;
        }
        maskl=solve(nwv)<<1;
    }
    {
        vector<pair<mp,int> > nw;
        for(int i=0;i<v.size();i++){
            nw.PB(II(II(v[i+1],v[i]),i/2));
            i++;
        }
        sort(ALL(nw));
        vector<int> nwv(v.size()/2);
        int cnt=0;
        rep(i,nw.size()){
            if(i&&nw[i].first!=nw[i-1].first) cnt++;
            nwv[nw[i].second]=cnt;
        }
        maskr=solve(nwv)<<1|1;
    }
    vector<int> L(v.size()),R(v.size());
    rep(i,v.size()) L[i]=v[i^maskl],R[i]=v[i^maskr];
    if(L<R) return maskl;
    return maskr;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(1<<n);
    rep(i,1<<n){
        char c;
        cin>>c;
        v[i]=c-'a';
    }
    int mask=solve(v);
    rep(i,1<<n) cout<<char('a'+v[i^mask]);
    cout<<endl;
    return 0;
}