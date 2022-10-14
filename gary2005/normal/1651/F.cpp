/**
 *    author:  gary
 *    created: 10.03.2022 22:28:18
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
int MAGIC;
const int MAXN=2e5+10;
int n,c[MAXN],r[MAXN],pre[MAXN],a[MAXN];
vector<mp> block;
int tag[MAXN];// block[i],-1 
vector<pair<int,pair<long long ,long long> > > init[1400];
long long pushdown(int idx,int t){
    if(tag[idx]!=-1){
        rb(i,block[idx].first,block[idx].second){
            pre[i]=tag[idx];
            a[i]=0;
        }
    }
    tag[idx]=-1;
    long long sum=0;
    rb(i,block[idx].first,block[idx].second){
        int tmp=(c[i]-a[i]+r[i]-1)/r[i];
        a[i]+=min(t-pre[i],tmp)*r[i];
        check_min(a[i],c[i]);
        pre[i]=t;
        sum+=a[i];
    }
    return sum;
}
long long querysum(int idx,long long t){
    if(init[idx][0].first<t) return init[idx][0].second.second;
    if(init[idx].back().first>=t) return init[idx].back().second.first*t;
    int l=0,r=init[idx].size();
    while (l<r-1)
    {
        int mid=(l+r)>>1;
        if(init[idx][mid].first>=t) l=mid;
        else r=mid;
    }
    return init[idx][l].second.first*t+init[idx][r].second.second;
}
long long ans;
int main(){
    scanf("%d",&n);
    MAGIC=ceil(sqrt(n*log2(n)/2));
    check_max(MAGIC,1);
    rb(i,1,n) scanf("%d%d",&c[i],&r[i]);
    check_min(MAGIC,n);
    for(int i=1;i<=n;i+=MAGIC){
        block.PB(II(i,min(n,i+MAGIC-1)));
    }
    rb(i,1,n) a[i]=c[i],pre[i]=0;
    rep(i,block.size()) tag[i]=-1;
    rep(i,block.size()){
        int L,R;
        L=block[i].first;
        R=block[i].second;
        rb(j,L,R){
            init[i].PB(II(c[j]/r[j],II(r[j],c[j])));
        }
        sort(ALL(init[i]));
        reverse(ALL(init[i]));
        rep(j,init[i].size()) if(j) init[i][j].second.first+=init[i][j-1].second.first;
        rl(j,init[i].size()-1,0) if(j!=init[i].size()-1) init[i][j].second.second+=init[i][j+1].second.second;
    }
    int q;
    scanf("%d",&q);
    while (q--){
        int t;
        long long h;
        scanf("%d%lld",&t,&h);
        int now=1;
        while (true)
        {
            if(now>n){
                ans+=h;
                break;
            }
            int idx=(now-1)/MAGIC;
            long long nows;
            if(tag[idx]==-1){
                nows=pushdown(idx,t);
            }
            else{
                nows=querysum(idx,t-tag[idx]);
            }
            if(nows<=h){
                h-=nows;
                tag[idx]=t;
            }
            else{
                pushdown(idx,t);
                rb(i,now,n){
                    if(a[i]>=h){
                        a[i]-=h;
                        break;
                    }
                    else{
                        h-=a[i];
                        a[i]=0;
                    }
                }
                break;
            }
            now+=MAGIC;
        }
    }
    cout<<ans<<endl;
    return 0;
}