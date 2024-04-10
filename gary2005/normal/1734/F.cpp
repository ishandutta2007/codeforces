/**
 *    author:  gary
 *    created: 23.09.2022 20:02:38
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
    LL n,m;
    cin>>n>>m;
    LL ans=0;
    map<pair<LL,LL> ,LL> save;
    LL x=1ll<<61;
    save[II(n,n+m-1)]=1;
    while (x>1){
        map<pair<LL,LL>,LL> nex;
        LL mid=(x>>1);
        for(auto it:save){
            if((it.first.first==0&&it.first.second==x-1)||!it.second) continue;
            if(it.first.second<mid){
                nex[it.first]+=it.second;
            }
            else if(it.first.first>=mid){
                nex[II(it.first.first-mid,it.first.second-mid)]-=it.second;
                ans+=it.second*(it.first.second-it.first.first+1);
            }
            else{
                nex[II(it.first.first,mid-1)]+=it.second;
                LL x,y,h;
                x=it.first.first;
                y=it.first.second-mid+1;
                h=mid-it.first.first;
                if(x){
                    LL z=min(x,y);
                    nex[II(h,h+z-1)]-=it.second;
                    ans+=it.second*z;
                }
                if(x<y){
                    y-=x;
                    nex[II(it.first.second-mid-y+1,it.first.second-mid)]+=it.second;
                }
            }
        }
        nex.swap(save);
        x=mid;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }   
    return 0;
}