/**
 *    author:  gary
 *    created: 05.08.2022 17:10:47
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
const int MAXN=1e6+10;
int n,e[MAXN];
LL k,a[MAXN];
LL gcd(LL A,LL B){
    return B==0? A:gcd(B,A%B);
}
LL dp[2][1<<11][12];
bool can[1<<11];
LL prod[1<<11];
int lest[1<<11];
vector<LL> p;
int N;
void clr(int i){
    rep(j,1<<N)
    rb(k,0,N)
    dp[i][j][k]=1e18;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) cin>>e[i];
    LL g=0;
    rb(i,1,n) g=gcd(g,a[i]);
    if(g==1){
        cout<<0<<endl;
        return 0;
    }
    for(LL i=2;i*i<=g;i++){
        if(g%i==0){
            while (g%i==0){
                g/=i;
            }
            p.push_back(i);
        }
    }
    if(g>1) p.push_back(g);
    N=p.size();
    map<vector<int>,vector<int > > M;
    rb(i,1,n){
        vector<int> cnt(p.size(),0);
        rep(j,p.size()){
            int c=0;
            while (a[i]%p[j]==0){
                a[i]/=p[j];
                ++c;
            }
            cnt[j]=c;
        }
        M[cnt].push_back(e[i]);
    }
    int now,pre;
    now=1,pre=0;
    clr(pre);
    dp[pre][0][0]=0;
    for(auto it:M){
        memcpy(dp[now],dp[pre],sizeof(dp[now]));
        vector<LL> pref;
        sort(ALL(it.second));
        if(it.second.size()>p.size()) it.second.resize(p.size());
        for(auto tmp:it.second){
            if(pref.empty()) pref.push_back(tmp);
            else{
                LL z=pref.back()+tmp;
                pref.push_back(z);
            }
        }
        prod[0]=1;
        vector<LL> z(N,1);
        rep(j,N){
            rb(k,1,it.first[j]){
                z[j]*=p[j];
            }
        }
        rep(mask,1<<N){
            rep(j,N){
                if((mask>>j)&1){
                    prod[mask]=prod[(mask^(1<<j))]*z[j];
                    break;
                }
            }
            can[mask]=(prod[mask]<=k);
        }
        memset(lest,63,sizeof(lest));
        lest[0]=0;
        rep(mask,1<<N) if(mask){
            if(can[mask]){
                lest[mask]=1;
                continue;
            }
            int tmp=mask&-mask;
            tmp^=mask;
            for(int smask=tmp;smask;smask=(smask-1)&tmp){
                if(can[smask]){
                    check_min(lest[mask],lest[smask^mask]+1);
                }
            }
        }
        rep(mask,1<<N){
            rb(j,0,N){
                if(dp[pre][mask][j]!=1e18){
                    int tmp=((1<<N)-1)^mask;
                    for(int smask=tmp;smask;smask=(smask-1)&tmp){
                        if(lest[smask]+j<=N&&lest[smask]<=it.second.size()){
                            check_min(dp[now][mask|smask][j+lest[smask]],dp[pre][mask][j]+pref[lest[smask]-1]);
                        }
                    }
                }
            }
        }
        swap(now,pre);
    }
    LL ans=1e18;
    rb(j,0,N){
        if(dp[pre][(1<<N)-1][j]!=1e18){
            check_min(ans,dp[pre][(1<<N)-1][j]*j);
        }
    }
    if(ans==1e18) ans=-1;
    cout<<ans<<endl;
    return 0;
}