/**
 *    author:  gary
 *    created: 06.09.2022 22:26:18
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
    int n,m;
    cin>>n>>m;
    if(m<n||(n%2==0&&m%2==1)){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        if(n&1){
            cout<<m-(n-1)<<' ';
            rb(i,1,n-1) cout<<1<<' ';
        }
        else{
            int x=m%n;
            rb(i,1,n){
                if(i<=x) cout<<(m/n)+1<<' ';
                else cout<<m/n<<' ';
            }
            cout<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}