#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    __int128 need=sum;
    need*=n-2;
    if(need%n!=0){
        printf("0\n");
        return;
    }
    need=need/n;
    map<int,int> m;
    LL ans=0;
    for(int i =0;i<n;i++){
        ans+=m[sum-need-a[i]];
        m[a[i]]++;
    }
    printf("%lld\n",ans);
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
*/