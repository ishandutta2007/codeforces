/**
 *    author:  gary
 *    created: 09.05.2022 01:11:45
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
const int MOD=998244353;
int n,k,v[1000000+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        rb(i,1,n) cin>>v[i];
        int ans=1;
        rb(i,n-k+1,n) if(v[i]!=-1&&v[i]!=0) ans=0;
        rb(i,1,n){
            if(i-k<=0){
                ans=1ll*i*ans%MOD;
            }
            else{
                if(v[i-k]==-1) ans=1ll*i*ans%MOD;
                else if(v[i-k]==0) ans=1ll*(min(i-1,k)+1)*ans%MOD;
                else ans=(v[i-k]+k<i)*ans;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}