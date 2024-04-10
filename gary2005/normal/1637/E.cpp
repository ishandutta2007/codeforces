/**
 *    author:  gary
 *    created: 12.02.2022 22:26:42
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
int n,m;
int a[300000+10];
void solve(){
    cin>>n>>m;
    rb(i,1,n) cin>>a[i];
    map<int,int> cnt;
    rb(i,1,n) cnt[a[i]]++;
    map<int,vector<int> > each;
    for(auto ite=cnt.begin();ite!=cnt.end();ite++) each[ite->second].PB(ite->first);
    vector<pair<int,vector<int> > > v;
    for(auto ite=each.begin();ite!=each.end();ite++) v.PB(*ite);
    set<mp> bad;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        bad.insert(II(u,v));
        bad.insert(II(v,u));
    }
    LL answer=-1e18;
    rep(i,v.size()){
        rep(j,i+1){
            int mx=-1;
            rl(x,v[i].second.size()-1,0){
                rl(y,(j==i? x-1:v[j].second.size()-1),mx+1){
                    int X,Y;
                    X=v[i].second[x];
                    Y=v[j].second[y];
                    if(bad.find(II(X,Y))==bad.end()){
                        // cout<<X<<" "<<Y<<endl;
                        mx=y;
                        check_max(answer,1ll*(v[i].first+v[j].first)*(X+Y));
                        break;
                    }
                }
            }
        }
    }
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}