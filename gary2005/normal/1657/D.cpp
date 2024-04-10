/**
 *    author:  gary
 *    created: 22.03.2022 22:28:49
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
const int MAXN=1e6+10;
int n,C,c[MAXN],d[MAXN],h[MAXN],m;
LL t[MAXN];
int ans[MAXN];
LL mx[MAXN];
int main(){
    scanf("%d%d",&n,&C);
    rb(i,1,C) t[i]=-1;
    rb(i,1,n) scanf("%d%d%d",&c[i],&d[i],&h[i]),check_max(t[c[i]],1ll*d[i]*h[i]);
    rb(i,1,C) mx[i]=-1e18;
    rb(i,1,C){
        if(t[i]!=-1){
            rb(j,1,C/i){
                check_max(mx[j*i],1ll*t[i]*j-1);
            }
        }
    }
    rb(i,2,C) check_max(mx[i],mx[i-1]);
    cin>>m;
    vector<pair<LL,int> > queries;
    rb(i,1,m){
        LL d,h;
        scanf("%lld%lld",&d,&h);
        queries.PB(II(d*h,i));
        ans[i]=-1;
    }
    sort(ALL(queries));
    reverse(ALL(queries));
    int mn=INF;
    int g=C;
    for(auto it:queries){
        while (C>1&&mx[g-1]>=it.first){
            g--;
        }
        if(mx[g]>=it.first) ans[it.second]=g;
    }
    rb(i,1,m){
        printf("%d ",ans[i]);
    }
    cout<<endl;
    return 0;
}