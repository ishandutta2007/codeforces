/**
 *    author:  gary
 *    created: 30.09.2022 22:31:36
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
        vector<int> a(n),b(n);
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];
        LL ans=0;
        rep(i,n) ans+=b[i];
        vector<int> v[2];
        rep(i,n) v[a[i]].push_back(b[i]);
        rep(i,2) sort(ALL(v[i])),reverse(ALL(v[i]));
        int x=v[0].size(),y=v[1].size();
        LL B=0;
        if(x){
            int p1=0,p2=0;
            LL s=0;
            rb(i,1,INF){
                if(i&1){
                    if(p2==y) break;
                    s+=v[1][p2++];
                }
                else{
                    if(p1==x-1) break;
                    s+=v[0][p1++];
                }
            }
            check_max(B,s);
        }
        swap(v[0],v[1]);
        swap(x,y);
        if(x){
            int p1=0,p2=0;
            LL s=0;
            rb(i,1,INF){
                if(i&1){
                    if(p2==y) break;
                    s+=v[1][p2++];
                }
                else{
                    if(p1==x-1) break;
                    s+=v[0][p1++];
                }
            }
            check_max(B,s);
        }
        cout<<ans+B<<endl;
    }
    
    return 0;
}