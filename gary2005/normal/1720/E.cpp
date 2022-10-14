/**
 *    author:  gary
 *    created: 18.08.2022 21:32:37
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
const int MAXN=505;
int n,k,a[MAXN][MAXN],p[MAXN][MAXN];
vector<mp> pos[MAXN*MAXN];
vector<pair<mp,mp> > rect;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    set<int> se;
    rb(i,1,n) rb(j,1,n) cin>>a[i][j],se.insert(a[i][j]),pos[a[i][j]].emplace_back(i,j);
    if(se.size()<=k){
        cout<<k-se.size()<<endl;
        return 0;
    }
    rb(i,1,n*n){
        if(!pos[i].empty()){
            int xl,xr,yl,yr;
            xl=yl=INF;
            xr=yr=-INF;
            for(auto &[x,y]:pos[i]){
                check_min(xl,x),check_min(yl,y);
                check_max(xr,x),check_max(yr,y);
            }
            rect.emplace_back(II(xl,xr),II(yl,yr));
        }
    }
    rb(d,1,n){
        memset(p,0,sizeof(p));
        for(auto it:rect){
            int xl,xr,yl,yr;
            tie(xl,xr)=it.first;
            tie(yl,yr)=it.second;
            // cout<<d<<" "<<xl<<" "<<xr<<' '<<yl<<' '<<yr<<endl;
            if(max(xr-xl+1,yr-yl+1)<=d){
                int XL,XR,YL,YR;
                XL=max(1,xr-d+1);
                XR=xl+1;
                YL=max(1,yr-d+1);
                YR=yl+1;
                p[XL][YL]++;
                p[XR][YR]++;
                p[XR][YL]--;
                p[XL][YR]--;
            }
        }
        rb(i,1,n-d+1) rb(j,1,n-d+1) {
            p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
            if(p[i][j]==se.size()-k||p[i][j]==se.size()-k+1){
                cout<<1<<endl;
                return 0;
            }
        }
    }
    cout<<2<<endl;
    return 0;
}