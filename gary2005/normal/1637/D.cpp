/**
 *    author:  gary
 *    created: 12.02.2022 22:26:38
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
const int MAXN=101;
int n,a[MAXN],b[MAXN];
void solve(){
    int sum=0;
    cin>>n;
    int rest=0;
    int s=0;
    rb(i,1,n) cin>>a[i],s+=a[i],rest+=a[i]*a[i];
    rb(i,1,n) cin>>b[i],s+=b[i],rest+=b[i]*b[i];
    bitset<10000+10> BS;
    rest=(n-2)*rest;
    BS.set(0);
    rb(i,1,n){
        BS=(BS<<a[i])|(BS<<b[i]);
    }
    int ann=INF;
    rb(i,0,10000){
        if(BS[i]){
            check_min(ann,i*i+(s-i)*(s-i));
        }
    }
    cout<<rest+ann<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}