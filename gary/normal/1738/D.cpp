/**
 *    author:  gary
 *    created: 30.09.2022 22:31:55
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> to(n+2);
        rb(i,1,n) cin>>to[i];
        int k=n;
        to[0]=INF;
        rb(i,0,n-1){
            if(to[i]>i&&to[i+1]<=i){
                k=i;
                break;
            }
        }
        vector<vector<int> > son(n+5);
        rb(i,1,n) son[(to[i])%(n+1)].push_back(i);
        int now=0;
        int cnt=0;
        cout<<k<<endl;
        while (cnt<n){
            vector<int> vec=son[now];
            rep(i,vec.size()-1) if(son[vec[i]].size()) {
                swap(vec[i],vec.back());
                break;
            }
            for(auto it:vec) cout<<it<<' ';
            cnt+=vec.size();
            now=vec.back();
        }
        cout<<'\n';
    }
    return 0;
}