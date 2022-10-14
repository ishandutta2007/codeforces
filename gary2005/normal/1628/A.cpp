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
const int MAXN=2e5+1;
int n,a[MAXN];
void solve(){
    map<int,int> lst;
    cin>>n;
    rb(i,1,n) cin>>a[i],lst[a[i]]=i;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int now=0;
        int j=i;
        map<int,bool> app;
        app[a[j]]=1;
        while((lst.find(now)!=lst.end()&&lst[now]>j)||app[now]){
            if(app[now]){
                now++;
            }
            else{
                while(true){
                    j++;
                    app[a[j]]=1;
                    if(a[j]==now) break;
                }
                now++;
            }
        }
        ans.PB(now);
        i=j;
    }
    // cout<<"-\n";
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<' ';
    }
    cout<<endl;
    // cout<<"-\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}