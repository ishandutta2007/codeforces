/**
 *    author:  gary
 *    created: 11.08.2022 18:07:18
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
const int MAXN=1e5+10;
const int MOD=1e9+7;
int n,q,a[MAXN],b,ans[MAXN],pw[MAXN];
vector<pair<mp,int> > queries;
bool cmp(pair<mp,int> A,pair<mp,int> B){
    return A.first.first/b==B.first.first/b? A.first.second<B.first.second:A<B;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    b=ceil(sqrt(n));
    rb(i,1,n) cin>>a[i];
    pw[0]=1;
    rb(i,1,n) pw[i]=(pw[i-1]<<1)%MOD;
    rb(id,1,q){
        int l,r;
        cin>>l>>r;
        if(r-l+1<=b){
            vector<pair<LL,int> > sta;
            vector<int> le;
            int sum=0;
            rb(i,l,r){
                sum=(sum+(a[i]%MOD+MOD)%MOD)%MOD;
                sta.push_back(II(a[i],(a[i]%MOD+MOD)%MOD));
                le.push_back(1);
                while (sta.size()>=2&&sta.back().first>0){
                    auto A=sta.back();int lA=le.back();
                    sta.pop_back();le.pop_back();
                    auto B=sta.back();int lB=le.back();
                    sta.pop_back();le.pop_back();
                    (sum=sum+1ll*A.second*(pw[lB]-1)%MOD)%=MOD;
                    A.first=(((LL)(1e18)-B.first)>>min(60,lB))<A.first? (LL)(1e18):min((LL)(1e18),(A.first<<lB)+B.first);
                    A.second=(1ll*A.second*pw[lB]+B.second)%MOD;
                    sta.push_back(A);
                    le.push_back(lA+lB);
                }
            }
            ans[id]=(2ll*sum-sta[0].second+MOD)%MOD;
        }
        else{
            queries.emplace_back(II(l,r),id);
        }
    }
    sort(ALL(queries),cmp);
    vector<pair<LL,int> > sta;
    vector<int> le;
    int sum=0;
    int i=0;
    rep(p,queries.size()){
        if(p==0||queries[p].first.first/b!=queries[p-1].first.first/b){
            sum=0;
            sta.clear();
            sta.reserve(n);
            le.clear();
            le.reserve(n);
            i=(queries[p].first.first/b+1)*b-1;
        }
        while (i<queries[p].first.second){
            ++i;
            sum=(sum+(a[i]%MOD+MOD)%MOD)%MOD;
            sta.push_back(II(a[i],(a[i]%MOD+MOD)%MOD));
            le.push_back(1);
            while (sta.size()>=2&&sta.back().first>0){
                auto A=sta.back();int lA=le.back();
                sta.pop_back();le.pop_back();
                auto B=sta.back();int lB=le.back();
                sta.pop_back();le.pop_back();
                (sum=sum+1ll*A.second*(pw[lB]-1)%MOD)%=MOD;
                A.first=(((LL)(1e18)-B.first)>>min(60,lB))<A.first? (LL)(1e18):min((LL)(1e18),(A.first<<lB)+B.first);
                A.second=(1ll*A.second*pw[lB]+B.second)%MOD;
                sta.push_back(A);
                le.push_back(lA+lB);
            }
        }
        vector<pair<LL,int> > sta2;
        vector<int> le2;
        sta2.reserve(b);
        le2.reserve(b);
        int sum2=sum;
        rb(i,queries[p].first.first,(queries[p].first.first/b+1)*b-1){
            sum2=(sum2+(a[i]%MOD+MOD)%MOD)%MOD;
            sta2.push_back(II(a[i],(a[i]%MOD+MOD)%MOD));
            le2.push_back(1);
            while (sta2.size()>=2&&sta2.back().first>0){
                auto A=sta2.back();int lA=le2.back();
                sta2.pop_back();le2.pop_back();
                auto B=sta2.back();int lB=le2.back();
                sta2.pop_back();le2.pop_back();
                (sum2=sum2+1ll*A.second*(pw[lB]-1)%MOD)%=MOD;
                A.first=(((LL)(1e18)-B.first)>>min(60,lB))<A.first? (LL)(1e18):min((LL)(1e18),(A.first<<lB)+B.first);
                A.second=(1ll*A.second*pw[lB]+B.second)%MOD;
                sta2.push_back(A);
                le2.push_back(lA+lB);
            }
        }
        sta2.push_back(sta[0]);
        le2.push_back(le[0]);
        while (sta2.size()>=2&&sta2.back().first>0){
            auto A=sta2.back();int lA=le2.back();
            sta2.pop_back();le2.pop_back();
            auto B=sta2.back();int lB=le2.back();
            sta2.pop_back();le2.pop_back();
            (sum2=sum2+1ll*A.second*(pw[lB]-1)%MOD)%=MOD;
            A.first=(((LL)(1e18)-B.first)>>min(60,lB))<A.first? (LL)(1e18):min((LL)(1e18),(A.first<<lB)+B.first);
            A.second=(1ll*A.second*pw[lB]+B.second)%MOD;
            sta2.push_back(A);
            le2.push_back(lA+lB);
        }
        ans[queries[p].second]=(2ll*sum2-sta2[0].second+MOD)%MOD;
    }
    rb(i,1,q) cout<<ans[i]<<'\n';
    return 0;
}