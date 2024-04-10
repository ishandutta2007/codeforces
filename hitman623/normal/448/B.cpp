#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
bool f(string s,string t){
    int cur=0;
    rep(i,0,sz(s)) if(cur<sz(t) and s[i]==t[cur]) cur++;
    return cur==sz(t);
}
string s,t;
void solve(){
    cin>>s>>t;
    if(f(s,t)) cout<<"automaton"<<endl;
    else{
        string ss=s,tt=t;
        sort(all(ss));
        sort(all(tt));
        if(ss==tt){
            cout<<"array"<<endl;
        }
        else if(f(ss,tt)){
            cout<<"both"<<endl;
        }
        else cout<<"need tree"<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}