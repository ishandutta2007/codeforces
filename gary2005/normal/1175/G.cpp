/**
 *    author:  gary
 *    created: 15.03.2022 12:51:04
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
#define calc(A,x) A.FIR*x+A.SEC
#define cross(A,B) (double)(A.SEC-B.SEC)/(B.FIR-A.FIR)
#define bad(A,B,C) (calc(B,cross(A,B))>=calc(C,cross(A,B)))
struct convex_hull{
    vector<mp> v[15];
    int f(int x){
        int ans=-INF;
        rep(i,15){
            if(!v[i].empty()){
                int l=0,r=v[i].size();
                while (l<r-1){
                    int mid=(l+r)>>1;
                    if(calc(v[i][mid],x)>calc(v[i][mid-1],x)) l=mid;
                    else r=mid;
                }
                check_max(ans,calc(v[i][l],x));
            }
        }
        return ans;
    }
    convex_hull(){}
    convex_hull(mp A){v[0]={A};}
};
vector<mp> merge(vector<mp> A,vector<mp> B){
    int pt=0;
    vector<mp> rest;
    for(auto it:A){
        while(pt!=B.size()&&B[pt]<it) rest.PB(B[pt++]);
        rest.PB(it);
    }
    while (pt<B.size()){
        rest.PB(B[pt++]);
    }
    vector<double> c;
    rest.swap(A);
    rest.clear();
    for(auto it:A){
        while (!c.empty()&&calc(rest.back(),c.back())<=calc(it,c.back())){
            c.pop_back();
            rest.pop_back();
        }
        if(!rest.empty()) c.push_back(cross(rest.back(),it));
        rest.push_back(it);
    }
    return rest;
}
void merge(convex_hull &A,convex_hull &B){
    rl(i,14,0){
        int now=i;
        while (true){
            if(B.v[now].empty()) break;
            if(A.v[now].empty()){ A.v[now].swap(B.v[now]);break;}
            B.v[now+1]=merge(A.v[now],B.v[now]);
            A.v[now].clear();
            B.v[now].clear();
            now++;
        }
    }
}
const int MAXN=2e4+10;
const int MAXK=105;
int n,k,dp[MAXN][MAXK],a[MAXN],fa[MAXN][15];
vector<mp> glo;
void upd(int id){
    int z=0;
    if(fa[id-1][0]==0||!bad(glo[fa[id-1][0]-1],glo[id-2],glo[id-1])){
        z=id-1;
    }
    else{
        z=id-1;
        rl(j,14,0) if(fa[fa[z][j]][0]&&bad(glo[fa[fa[z][j]][0]-1],glo[fa[z][j]-1],glo[id-1])) z=fa[z][j];
        z=fa[z][0];
    }
    fa[id][0]=z;
    rb(j,1,14) fa[id][j]=fa[fa[id][j-1]][j-1];
}
void trans(int j){
    glo.clear();
    vector<pair<int,convex_hull> > sta;// max_a 
    rb(i,j+1,n){
        sta.push_back(II(a[i],convex_hull(II(i-1,-dp[i-1][j]))));
        while (sta.size()>=2&&sta[sta.size()-2].first<=a[i]){
            merge(sta[sta.size()-2].second,sta[sta.size()-1].second);
            sta.pop_back();
            glo.pop_back();
        }
        sta.back().first=a[i];
        glo.push_back(II(a[i],-sta.back().second.f(a[i])));
        memset(fa[glo.size()],0,sizeof(fa[glo.size()]));
        upd(glo.size());
        int l=glo.size();
        rl(k,14,0){
            if(fa[fa[l][k]][0]){
                if(calc(glo[fa[l][k]-1],i)>calc(glo[fa[fa[l][k]][0]-1],i)) l=fa[l][k];
            }
        }
        dp[i][j+1]=calc(glo[l-1],i);
        if(fa[l][0])
        check_min(dp[i][j+1],calc(glo[fa[l][0]-1],i));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;rb(i,1,n) cin>>a[i];
    int mx=-INF;
    rb(i,1,n){
        check_max(mx,a[i]);
        dp[i][1]=i*mx;
    }
    rb(i,1,k-1){
        trans(i);
    }
    cout<<dp[n][k]<<endl;
    return 0;
}