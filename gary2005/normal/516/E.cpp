/**
 *    author:  gary
 *    created: 27.07.2022 16:40:34
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
LL exGcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exGcd(b,a%b,x,y);
    LL t = x; x = y;
    y = t-a/b*y;
    return r;
}
int gcd(int A,int B){
    return B==0? A:gcd(B,A%B);
}
const int MAXN=1e5+20;
int Nx,Mx;
int Query_Inv(int step,int MOD){
    LL x,y;
    exGcd(step,MOD,x,y);
    x%=MOD;
    x+=MOD;
    x%=MOD;
    return x;
}
vector<pair<int,LL> > g[MAXN<<4];
LL dis[MAXN<<4];
int nn,mm;
int QueryID(vector<int> &v,int x){
    return lower_bound(ALL(v),x)-v.begin();
}
bool cmpn(int A,int B){
    return 1ll*A*Nx%nn<1ll*B*Nx%nn;
}
bool cmpm(int A,int B){
    return 1ll*A*Mx%mm<1ll*B*Mx%mm;
}
LL solve(int n,int m,vector<int> a,vector<int> b){
    nn=n,mm=m;
    if(a.size()==n&&b.size()==m) return -INF;
    if(!(a.size()+b.size())) return 1e18;
    vector<int> usefulL,usefulR;
    Nx=Query_Inv(m,n);
    Mx=Query_Inv(n,m);
    for(auto it:a) usefulL.push_back(it%n),usefulR.push_back(it%m);
    for(auto it:b) usefulL.push_back(it%n),usefulR.push_back(it%m);
    vector<int> tmp;
    for(auto it:usefulL) tmp.push_back(it),tmp.push_back(((it-m)%n+n)%n);
    usefulL.swap(tmp);tmp.clear();
    for(auto it:usefulR) tmp.push_back(it),tmp.push_back(((it-n)%m+m)%m);
    usefulR.swap(tmp);tmp.clear();
    sort(ALL(usefulL)),usefulL.erase(unique(ALL(usefulL)),usefulL.end());
    sort(ALL(usefulR)),usefulR.erase(unique(ALL(usefulR)),usefulR.end());
    int N=usefulL.size()+usefulR.size();
    rb(i,0,N) g[i].clear(),dis[i]=1e18;
    dis[0]=0;
    tmp=usefulL;
    sort(ALL(tmp),cmpn);
    rep(i,tmp.size()){
        int s,t;
        s=tmp[i],t=tmp[(i+1)%tmp.size()];
        LL dis=(t-s+n)%n;
        dis=1ll*dis*Nx%n*m;
        g[QueryID(usefulL,s)+1].emplace_back(QueryID(usefulL,t)+1,dis);
    }
    tmp=usefulR;
    sort(ALL(tmp),cmpm);
    rep(i,tmp.size()){
        int s,t;
        s=tmp[i],t=tmp[(i+1)%tmp.size()];
        LL dis=(t-s+m)%m;
        dis=1ll*dis*Mx%m*n;
        g[QueryID(usefulR,s)+1+usefulL.size()].emplace_back(QueryID(usefulR,t)+1+usefulL.size(),dis);
    }
    for(auto it:a) g[0].emplace_back(QueryID(usefulL,it)+1,it),g[QueryID(usefulL,it)+1].emplace_back(QueryID(usefulR,it%m)+1+usefulL.size(),0);
    for(auto it:b) g[0].emplace_back(QueryID(usefulR,it)+usefulL.size()+1,it),g[QueryID(usefulR,it)+usefulL.size()+1].emplace_back(QueryID(usefulL,it%n)+1,0);
    priority_queue<pair<LL,int> ,vector<pair<LL,int > > ,greater<pair<LL,int> > > pq;
    pq.push(II(0,0));
    while (!pq.empty()){
        auto now=pq.top();
        pq.pop();
        if(dis[now.second]!=now.first) continue;
        for(auto it:g[now.second]) if(it.second+now.first<dis[it.first]){
            dis[it.first]=it.second+now.first;
            pq.push(II(now.first+it.second,it.first));
        }
    }
    for(auto it:a) dis[QueryID(usefulL,it)+1]=0;
    for(auto it:b) dis[QueryID(usefulR,it)+1+usefulL.size()]=0;
    // cout<<n<<' '<<m<<" "<<dis[0]<<" "<<dis[1]<<" "<<dis[2]<<endl;
    return *max_element(dis,dis+N+1);
}
int n,m,a,b,A[MAXN],B[MAXN];
LL answer=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>a;
    rb(i,1,a) cin>>A[i];
    cin>>b;
    rb(i,1,b) cin>>B[i];
    int g=gcd(n,m);
    if(g>a+b){
        cout<<-1<<endl;
        return 0;
    }
    vector<vector<int> > Ea(g),Eb(g);
    rb(i,1,a) Ea[A[i]%g].push_back(A[i]/g);
    rb(i,1,b) Eb[B[i]%g].push_back(B[i]/g);
    rep(i,g){
        // mod g = i
        auto tmp=solve(n/g,m/g,Ea[i],Eb[i]);
        if(tmp==1e18) answer=1e18;
        else
        check_max(answer,tmp*g+i);
    }
    if(answer==1e18) answer=-1;
    cout<<answer<<endl;
    return 0;
}
/*

3 2
1 0
0

2 4
1 0
1 2

*/