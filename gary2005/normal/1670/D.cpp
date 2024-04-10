/**
 *    author:  gary
 *    created: 06.05.2022 22:58:17
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
LL a[3];
LL calc(){
    LL ans=0;
    rep(i,3) rep(j,i) ans+=a[i]*a[j];
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        n=(n+1)/2;
        LL l=0,r=1e6;
        while (l<r-1){
            LL mid=(l+r)>>1;
            memset(a,0,sizeof(a));
            rep(i,3) a[i]=mid;
            // cout<<mid<<" "<<calc()<<endl;
            if(calc()>n) r=mid;
            else l=mid;
        }
        rep(i,3) a[i]=l;
        int pt=0;
        while (calc()<n){
            a[pt++]++;
        }
        int ans=0;
        // rep(i,9) cout<<a[i]<<endl;
        rep(i,3) ans+=a[i];
        // cout<<calc()<<endl;
        cout<<ans<<endl;
    }
    return 0;
}