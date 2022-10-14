/**
 *    author:  gary
 *    created: 03.06.2022 22:30:36
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<mp> edge;
    rb(i,1,m){
        string q;
        rb(j,1,m) q.PB('0'+(i==j));
        cout<<"? "<<q<<endl;
        ff;
        int x;
        cin>>x;
        edge.PB(II(x,i));
    }
    sort(ALL(edge));
    int ans=0;
    string q;
    rb(i,1,m) q.PB('0');
    int pre=0;
    for(auto it:edge){
        q[it.second-1]='1';
        cout<<"? "<<q<<endl;
        ff;
        int x;
        cin>>x;
        if(x-pre==it.first){
            ans+=it.first;
        }
        pre=x;
    }
    cout<<"! "<<ans<<endl;
    ff;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}