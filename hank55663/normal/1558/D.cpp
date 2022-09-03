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
#define MXN 3000000
int S[262144];
void add(int x,int k){
    for(int i = x;i<262144;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int query2(int x){
    int sum=0,res=0;
    for(int i = 17;i>=0;i--){
        if(sum+S[res+(1<<i)]<x){
            res+=(1<<i);
            sum+=S[res];
        }
    }
    return res;
}
const int mod=998244353;
LL fra[400005],inv[400005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pii> v;
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.pb(mp(x,y));
    }
    reverse(v.begin(),v.end());
    vector<int> rm;
    vector<int> cal;
    for(auto it:v){
        int a=query2(it.y)+1;
        rm.pb(a);
        add(a,-1);
        int b=query2(it.y)+1;
        if(b-1==a){
            cal.pb(a);
        }
    }
    sort(cal.begin(),cal.end());
    for(auto it:rm)add(it,1);
    printf("%lld\n",C(n-cal.size()-1+n,n));
}
int main(){
    for(int i = 1;i<=200000;i++){
        add(i,1);
    }
    fra[0]=1;
    for(int i = 1;i<=400000;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    inv[400000]=f_pow(fra[400000],mod-2);
    for(int i = 399999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;

    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
6 4 2 3 5 1
*/