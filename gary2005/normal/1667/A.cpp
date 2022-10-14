/**
 *    author:  gary
 *    created: 21.04.2022 00:03:29
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
int a[5005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    rb(i,1,n) cin>>a[i];
    LL ans=1e18;
    rb(i,1,n){
        LL pre=0,tmp=0;
        rb(j,i+1,n){
            pre++;
            LL t=(pre+a[j]-1)/a[j];
            tmp+=t;
            t*=a[j];
            pre=t;
        }
        pre=0;
        rl(j,i-1,1){
            pre++;
            LL t=(pre+a[j]-1)/a[j];
            tmp+=t;
            t*=a[j];
            pre=t;
        }
        check_min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}