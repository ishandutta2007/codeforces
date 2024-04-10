/**
 *    author:  gary
 *    created: 07.10.2022 22:15:21
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
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt[26]={0};
    for(auto it:s) cnt[it-'a']++;
    rb(i,1,k){
        int x=min(25,n/k);
        rep(j,x){
            if(!cnt[j]){
                x=j;
                break;
            }
            else{
                cnt[j]--;
            }
        }
        cout<<char('a'+x);
    }
    cout<<endl;
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