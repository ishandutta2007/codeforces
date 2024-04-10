#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
LL S[200005];
int mod=1e9+7;
void add(int x,int k){
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
        S[i]%=mod;
    }
}
LL query(int x){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
        res%=mod;
    }
    return res;
}
vector<int> v[200005];
LL p[200005],q[200005];
LL p2[200005],q2[200005];
int a[200005];
LL go(int l,int r,int x,int y){
   // printf("%d %d %d %d\n",l,r,x,y);
    vector<int> tmp;
    for(int i = l;i<=r;i++){
        for(auto it:v[i]){
            if(it>=x&&it<=y)tmp.pb(it);
        }
    }
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    add(r+1,1);
    LL sum=1;
    for(auto it:tmp){
        p2[it]=((sum-query(a[it]))%mod+mod)%mod;
        add(a[it],p2[it]);
        sum+=p2[it];
       // printf("%lld %d ",p2[it],a[it]);
        sum%=mod;
    }
   // printf("\n");
    for(auto it:tmp){
        add(a[it],mod-p2[it]);
    }
    add(r+1,mod-1);
    LL res=0;
    for(auto it:tmp){
        res+=p[it]*p2[it]%mod;
        res%=mod;
    }
    //printf("%lld\n",res);
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);

    map<int,int> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]];
    }
    int Index=0;
    for(auto &it:m)it.y=++Index,v[Index].clear();
    for(int i = 0;i<n;i++){
        a[i]=m[a[i]];
        v[a[i]].pb(i);
    }

    for(int i = 0;i<n;i++){
        p[i]=query(a[i]-1)+1;
        add(a[i],p[i]);
    }
    for(int i = 0;i<n;i++){
        add(a[i],mod-p[i]);
    }
    LL sum=0;
    for(int i = n-1;i>=0;i--){
        q[i]=(((sum-query(a[i]))+1)%mod+mod)%mod;
        add(a[i],q[i]);
        sum+=q[i];
        sum%=mod;
    }
    for(int i = 0;i<n;i++){
        add(a[i],mod-q[i]);
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        ans+=p[i]*q[i];
        ans%=mod;
       // printf("%d %d\n",p[i],q[i]);
    }

    vector<pii> v;
    v.pb(mp(0,n));
    // printf("%lld\n",ans);
    for(int i = n-1;i>=0;i--){
        if(a[i]>v.back().x){
            ans-=go(v.back().x,a[i]-1,0,v.back().y-1);
            v.pb(mp(a[i],i));
            ans-=p[i]*q[i]%mod;
            ans+=mod;
            ans%=mod;
        }
    }
    ans-=go(v.back().x,Index,0,v.back().y-1);
    printf("%lld\n",(ans%mod+mod)%mod);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
8876666554222188 
*/