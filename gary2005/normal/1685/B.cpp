/**
 *    author:  gary
 *    created: 26.05.2022 01:33:04
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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<string> s;
    int n=a+b+2*(c+d);
    int cnt[2]={0,0};
    rb(i,1,n){
        char c;
        cin>>c;
        cnt[c=='B']++;
        if(s.empty()||s.back().back()==c){
            s.PB("");
        }
        s.back().PB(c);
    }
    vector<int> len[2][2];
    int cntab=0,cntba=0;
    if(cnt[0]!=a+c+d||cnt[1]!=b+c+d){
        cout<<"NO\n";
        return ;
    }
    for(auto it:s) len[it[0]=='B'][it.back()=='B'].PB(it.length()),cntab+=(it.length()-(it[0]=='B')-(it.back()=='A'))/2;
    if(cntab<c){
        cout<<"NO\n";
        return ;
    }
    sort(ALL(len[1][0]));
    sort(ALL(len[0][1]));reverse(ALL(len[0][1]));
    for(auto it:len[1][0]){
        int o=it/2-1;
        int can=min(cntab-c,o);
        cntab-=can;
        cntba+=(int)(o==can)+can;
    }
    rep(f,2) rep(g,2) if(f==g) for(auto it:len[f][g]){
        int o=it/2;
        int can=min(cntab-c,o);
        cntab-=can;
        cntba+=can;
    }
    for(auto it:len[0][1]){
        if(cntab>c){
            cntab--;
            int o=it/2-1;
            int can=min(cntab-c,o);
            cntab-=can;
            cntba+=can;
        }
    }
    if(cntba>=d){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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