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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL a[200005],b[200005];
    LL ea[200005],eb[200005];
    LL tota=0,totb=0;
    LL eat=0,ebt=0;
    for(int i = 0;i<n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
        tota+=a[i];
        totb+=b[i];
    }
    for(int i = 0;i<n;i++){
        if(tota>totb){
            if(b[i]>=m)eb[i]=m,ea[i]=0;
            else eb[i]=b[i],ea[i]=m-b[i];
            
        }
        else{
            if(a[i]>=m)ea[i]=m,eb[i]=0;
            else ea[i]=a[i],eb[i]=m-a[i];
        }
        eat+=ea[i];
        ebt+=eb[i];
    }
    tota-=eat;
    totb-=ebt;
    for(int i = 0;i<n;i++){
        if(tota>totb){
            int need=min((tota-totb)/2,min(eb[i],a[i]-ea[i]));
            tota-=need;
            totb+=need;
            eb[i]-=need;
            ea[i]+=need;
        }
        else{
            int need=min((totb-tota)/2,min(ea[i],b[i]-eb[i]));
            totb-=need;
            tota+=need;
            ea[i]-=need;
            eb[i]+=need;
        }
    }
    printf("%lld\n",abs(tota-totb));
    for(int i = 0;i<n;i++){
        printf("%lld %lld\n",ea[i],eb[i]);
    }
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/