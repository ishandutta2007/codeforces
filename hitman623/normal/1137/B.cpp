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
string s,t;
int lps[500005];
void pre(){ 
    int len = 0; 
    lps[0] = 0; // lps[0] is always 0 
    int i = 1; 
    while (i< sz(t)) { 
        if (t[i] == t[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else{ 
            if(len != 0){ 
                len = lps[len - 1]; 
            } 
            else{ 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
int ones,zeros,have1s,have0s,reqd1,reqd0;
void solve(){
    cin>>s>>t;
    pre();
    for(auto i:t){
        if(i=='1') ones++;
        else zeros++;
    }
    for(auto i:s){
        if(i=='1') have1s++;
        else have0s++;
    }
    if(have0s<zeros or have1s<ones){
        cout<<s<<endl;
        return;
    }
    have1s-=ones;
    have0s-=zeros;
    string res=t;
    int L=lps[sz(t)-1];
    string extra;
    rep(i,L,sz(t)) extra+=t[i];
    for(auto i:extra){
        if(i=='1') reqd1++;
        else reqd0++;
    }
    while(1){
        if(reqd1<=have1s and reqd0<=have0s){
            res+=extra;
            have0s-=reqd0;
            have1s-=reqd1;
        }
        else{
            rep(i,0,have0s) res+='0';
            rep(i,0,have1s) res+='1';
            break;
        }
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}