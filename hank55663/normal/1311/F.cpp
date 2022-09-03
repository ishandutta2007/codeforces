#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
//vector<int> v[100005];
LL S[200005],cnt[200005];
void add(int x,int k,LL *s){
    for(int i =x;i<200005;i+=i&-i){
        s[i]+=k;
    }
}
LL query(int x,LL *s){
    LL res=0;
    for(int i =x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
bool cmp(const pii &p,const pii &q){
    if(p.y!=q.y)return p.y<q.y;
    return p.x<q.x;
}
int main(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    map<int,int> m;
    for(int i = 0;i<n;i++)scanf("%d",&p[i].x),m[p[i].x];
    for(int i = 0;i<n;i++)scanf("%d",&p[i].y);
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }
    sort(p,p+n);
        LL ans=0;
        {
    LL sum=0,cnt=0;

    for(int i = 0;i<n;i++){
        if(p[i].y>=0){
            ans+=p[i].x*cnt-sum;
        }
        else{
            sum+=p[i].x;
            cnt++;
        }
    }
        }
    vector<pii> pos,neg;
    for(int i = 0;i<n;i++){
        if(p[i].y>=0)pos.pb(p[i]);
        else neg.pb(p[i]);
    }
    sort(pos.begin(),pos.end(),cmp);
    sort(neg.begin(),neg.end(),cmp);
    for(auto it:pos){
        add(m[it.x],1,cnt);
        add(m[it.x],it.x,S);
        ans+=query(m[it.x]-1,cnt)*it.x-query(m[it.x]-1,S);
    }
    MEM(cnt);
    MEM(S);
    for(auto it:neg){
        add(m[it.x],1,cnt);
        add(m[it.x],it.x,S);
        ans+=query(m[it.x]-1,cnt)*it.x-query(m[it.x]-1,S);
    }
    printf("%lld\n",ans);
}