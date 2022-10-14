/**
 *    author:  gary
 *    created: 01.08.2022 13:33:41
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
int mex(vector<int> v){
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    rep(i,v.size()) if(v[i]!=i) return i;
    return v.size();
}
const int MAXN=5002;
int sg[MAXN];
void init(){
    rb(i,2,5000){
        vector<int> z;
        rb(j,1,i-1){
            z.push_back(sg[j-1]^sg[i-j-1]);
        }
        sg[i]=mex(z);
    }
}
int querysg(int i){
    return i<=5000? sg[i]:sg[(i-2000)%34+2000];
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[2]={0,0};
    rep(i,s.length()) cnt[s[i]=='B']++;
    if(cnt[0]!=cnt[1]){
        cout<<(cnt[0]>cnt[1]? "Alice":"Bob")<<'\n';
    }
    else{
        int ans=0;
        for(int i=0;i<s.length();i++){
            int j=i;
            while (j+1<s.length()&&s[j+1]!=s[j]){
                ++j;
            }
            ans^=querysg(j-i+1);
            i=j;
        }
        cout<<(ans? "Alice":"Bob")<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}