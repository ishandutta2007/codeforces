/**
 *    author:  gary
 *    created: 19.05.2022 22:24:42
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int> (m)),b;
    rep(i,n){
        rep(j,m){
            cin>>v[i][j];
        }
    }
    b=v;
    rep(i,n) sort(ALL(b[i]));
    mp ans=II(0,0);
    rep(i,n){
        vector<int> diff;
        rep(j,m){
            if(b[i][j]!=v[i][j]){
                diff.PB(j);
            }
        }
        if(diff.size()>2){
            cout<<-1<<endl;
            return ;
        }
        if(diff.size()==2){
            ans=II(diff[0],diff[1]);
        }
    }
    rep(i,n){
        swap(v[i][ans.first],v[i][ans.second]);
        rep(j,m){
            if(b[i][j]!=v[i][j]){
                cout<<-1<<endl;
                return ;
            }
        }
    }
    cout<<ans.first+1<<" "<<ans.second+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}