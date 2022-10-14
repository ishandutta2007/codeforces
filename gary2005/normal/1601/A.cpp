/**
 *    author:  gary
 *    created: 25.10.2021 14:32:22
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
vector<int> al[MAXN];
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    int val=0;
    rep(i,30){
        int cnt=0;
        rb(j,1,n) cnt+=(a[j]>>i)&1;
        val=__gcd(val,cnt);
    }
    if(val==0){
        rb(i,1,n) printf("%d ",i);
    }
    else{
        for(auto it:al[val]){
            printf("%d ",it);
        }
    }
    puts("");
}
int main(){
    rb(i,1,200000){
        for(int j=i;j<=200000;j+=i) al[j].PB(i);
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}