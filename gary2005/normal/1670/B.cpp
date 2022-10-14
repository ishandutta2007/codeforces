/**
 *    author:  gary
 *    created: 06.05.2022 22:35:07
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
char c[100000+10],nw[100000+10];
void solve(){
    int n;
    cin>>n;
    bool spe[26]={0};
    rb(i,1,n) cin>>c[i];
    int k;
    cin>>k;
    rb(i,1,k){
        char a;
        cin>>a;
        spe[a-'a']=1;
    }
    set<int> Pos;
    set<int> Spe;
    rb(i,1,n){
        Pos.insert(i);
        if(spe[c[i]-'a']) Spe.insert(i);
    }
    int ans=0;
    while (true){
        bool ok=0;
        for(auto it:Spe){
            auto ite=Pos.lower_bound(it);
            if(ite!=Pos.begin()){
                ok=1;
                int x=*prev(ite);
                Pos.erase(prev(ite));
                if(Spe.find(x)!=Spe.end()) Spe.erase(x);
            }
        }
        if(!ok) break;
        ans++;
    }
    cout<<ans<<endl;
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