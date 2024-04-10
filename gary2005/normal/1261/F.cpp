/**
 *    author:  gary
 *    created: 03.08.2022 16:55:11
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
const int MAXN=100+20;
int na,nb;
LL la[MAXN],ra[MAXN],lb[MAXN],rb[MAXN];
vector<pair<LL,LL> > tmp;
void ivi(LL l,LL r,int k){
    if(l==r||(r-l+1==(1ll<<(k+1))&&__builtin_ctzll(l)>=k+1)){
        tmp.emplace_back(l,r);   
    }
    else{
        if(((l>>k)&1)==((r>>k)&1)) ivi(l,r,k-1);
        else{
            LL mid=l;
            mid>>=k;
            mid|=1;
            mid<<=k;
            ivi(l,mid-1,k-1);
            ivi(mid,r,k-1);
        }
    }
}
const int MOD=998244353;
LL answer=0;
const int MAXM=5705;
unsigned LL t[MAXM*MAXM];
bool cmp(unsigned LL &A,unsigned LL &B){
    return (A^((A&-A)-1))>(B^((B&-B)-1));
}
pair<LL,int> gen(unsigned LL A){
    A=~A;
    int g=__builtin_ctzll(~A);
    return II((A>>(g+1))<<g,g);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>na;
    rb(i,1,na) cin>>la[i]>>ra[i];
    cin>>nb;
    rb(i,1,nb) cin>>lb[i]>>rb[i];
    int cnt=0;
    rb(i,1,na) {
        tmp.clear();
        ivi(la[i],ra[i],59);
        auto z=tmp;
        for(auto it:z){
            int lena=__builtin_ctzll(it.second-it.first+1);
            rb(j,1,nb){
                tmp.clear();
                ivi(lb[j]>>lena,rb[j]>>lena,59-lena);
                for(auto it2:tmp){
                    int lenb=lena+__builtin_ctzll(it2.second-it2.first+1);
                    LL tmp=(it2.first<<lena)^(it.first);
                    tmp>>=lenb;
                    tmp<<=lenb;
                    tmp<<=1;
                    tmp|=(1ll<<lenb)-1;
                    t[cnt++]=~tmp;
                }
            }
        }
    }
    sort(t,t+cnt,cmp);
    pair<LL,char> pre=II(-1,-1);
    pair<LL,int> P=gen(t[cnt-1]);
    rl(i,cnt-2,0){
        auto now=gen(t[i]);
        if(now.first==P.first&&now.second<P.second) swap(t[i],t[i+1]);
        else P=now;
    }
    rep(i,cnt){
        auto it=gen(t[i]);
        if(pre.first!=-1&&(1ll<<pre.second)+pre.first-1>=it.first) continue;
        else pre=it;
        LL l=it.first;
        LL r=it.first+(1ll<<it.second)-1;
        answer+=(r-l+1)%MOD*((l+r)%MOD)%MOD;
        if(answer>=MOD) answer-=MOD;
    }
    answer=1ll*answer*(MOD+1)/2%MOD;
    cout<<answer<<endl;
    return 0;
}