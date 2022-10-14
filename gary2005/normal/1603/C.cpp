/**
 *    author:  gary
 *    created: 30.10.2021 22:30:36
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
const int MAXN=1e5+1;
const int MOD=998244353;
int n,a[MAXN];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    int ans=0;
    int sum=0;
    vector<pair<mp,int> > v;
    rb(r,1,n){
        v.PB(II(II(a[r],a[r]),1));
        int z=v.size();
        z-=2;
        while(z>=0){
            if(v[z].FIR.SEC>v[z+1].FIR.FIR){
                int nk=(a[z+1]+v[z+1].FIR.FIR-1)/v[z+1].FIR.FIR;
                add(sum,1ll*(z+1)*(nk-v[z].SEC)%MOD);
                v[z]=II(II(a[z+1]/nk,(a[z+1]+nk-1)/nk),nk);
                z--;
            }
            else{
                break;
            }
        }
        // for(auto it:v){
        //     cout<<"{"<<it.FIR.FIR<<" "<<it.FIR.SEC<<" "<<it.SEC<<endl;
        // }
        // cout<<r<<' '<<sum<<endl;
        add(ans,sum);
    }    
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}