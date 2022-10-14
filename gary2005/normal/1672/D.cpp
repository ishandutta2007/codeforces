/**
 *    author:  gary
 *    created: 23.04.2022 22:18:27
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
int a[200000+20],b[200000+20],n;
void solve(){
    cin>>n;
    vector<mp> va,vb;
    rb(i,1,n) {cin>>a[i];
    if(va.empty()||va.back().first!=a[i]) va.PB(II(a[i],1));
    else va.back().second++;;
    }
    rb(i,1,n){ cin>>b[i];
    if(vb.empty()||vb.back().first!=b[i]) vb.PB(II(b[i],1));
    else vb.back().second++;
    }
    map<int,int> Rest;
    while (!va.empty()){
        auto X=va.back();
        mp Y;
        if(vb.empty()) Y=II(INF,0);
        else Y=vb.back();
        if(X.first!=Y.first){
            if(Rest[X.first]<X.second){
                cout<<"NO\n";
                return ;
            }
            Rest[X.first]-=X.second;
            va.pop_back();
            continue;
        }
        if(X.second==Y.second){
            va.pop_back();
            vb.pop_back();
            continue;
        }
        if(X.second<Y.second){
            Rest[Y.first]+=Y.second-X.second;
            va.pop_back();
            vb.pop_back();
            continue;
        }
        if(X.second>Y.second){
            if(Rest[X.first]<X.second-Y.second){
                cout<<"NO\n";
                return ;
            }
            Rest[X.first]-=X.second-Y.second;
            va.pop_back();
            vb.pop_back();
            continue;
        }
    }
    cout<<"YES\n";
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