/**
 *    author:  gary
 *    created: 22.01.2022 22:10:12
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
int n;
void solve(){
    cin>>n;
    map<string,bool> app;
    set<char> se;
    vector<string> v;
    vector<string> ip;
    rb(i,1,n){
        string s;
        cin>>s;
        ip.PB(s);
    }
    for(auto s:ip){
        string t;
        t=s;
        reverse(ALL(t));
        v.PB(t);
        app[s]=1;
        if(app[t]){
            cout<<"YES"<<endl;
            return ;
        }
        t.POB();
        if(s.length()==3){
            if(app[t]){
                cout<<"YES"<<endl;return ;
            }
        }
        if(s.length()==2){
            if(app[t]){
                cout<<"YES"<<endl;return ;
            }
        }
        if(s.length()==1){
            for(auto ite=se.begin();ite!=se.end();ite++){
                string tmp;
                tmp.PB(*ite);
                tmp.PB(s[0]);
                app[tmp]=1;
            }
            se.insert(s[0]);
        }
        if(s.length()==2){
            for(auto ite=se.begin();ite!=se.end();ite++){
                string tmp;
                tmp.PB(*ite);
                tmp=tmp+s;
                app[tmp]=1;
            }
        }
    }
    se.clear();
    app.clear();
    reverse(ALL(v));
    for(auto s:v){
        string t;
        t=s;
        reverse(ALL(t));
        app[s]=1;
        if(app[t]){
            cout<<"YES"<<endl;return ;
        }
        t.POB();
        if(s.length()==3){
            if(app[t]){
                cout<<"YES"<<endl;return ;
            }
        }
        if(s.length()==2){
            if(app[t]){
                cout<<"YES"<<endl;return ;
            }
        }
        if(s.length()==1){
            for(auto ite=se.begin();ite!=se.end();ite++){
                string tmp;
                tmp.PB(*ite);
                tmp.PB(s[0]);
                app[tmp]=1;
            }
            se.insert(s[0]);
        }
        if(s.length()==2){
            for(auto ite=se.begin();ite!=se.end();ite++){
                string tmp;
                tmp.PB(*ite);
                tmp=tmp+s;
                app[tmp]=1;
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}