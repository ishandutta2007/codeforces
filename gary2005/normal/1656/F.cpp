/**
 *    author:  gary
 *    created: 24.03.2022 22:31:46
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
int n;
LL a[200000+20];
bool cmp(pair<LL,LL> A,pair<LL,LL> B){
    if(A.first!=B.first) return A.first>B.first;
    return A.second<B.second;
}
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    vector<pair<LL,LL> >   Line;
    LL k=0,b=0;
    rb(i,1,n-1){
        k+=a[i]+a[n];
        b+=a[i]*a[n];
    }
    Line.PB(II(k,b));
    rl(i,n-1,2){
        k-=a[i]+a[n];
        b-=a[i]*a[n];
        k+=a[i]+a[1];
        b+=a[i]*a[1];
        Line.PB(II(k,b));
    }
    sort(ALL(Line),cmp);
    vector<pair<LL,LL> > nw;
    for(auto it:Line){
        if(nw.empty()||nw.back().first!=it.first){
            nw.PB(it);
        }
        else{
            continue;
        }
    }
    Line=nw;
    if(Line[0].first<0||Line.back().first>0){
        cout<<"INF\n";
        return ;
    }
    LL ans=-2e18;
    if(Line[0].first==0) ans=Line[0].second;
    rep(i,Line.size()){
        if(i){
            LL x=(Line[i].second-Line[i-1].second)/(Line[i-1].first-Line[i].first);
            LL y=x*Line[i].first+Line[i].second;
            check_max(ans,y);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}