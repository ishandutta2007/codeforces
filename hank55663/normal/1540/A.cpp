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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
void solve(){
    int n;
    scanf("%d",&n);
    int d[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&d[i]);
    }
    LL sum=0,ans=0;
    LL tot=0;
    sort(d,d+n);
    ans=-d[n-1];
    for(int i = n-1;i>0;i--)d[i]-=d[i-1];

    for(int i = 1;i<n;i++){
        sum+=d[i];
        ans+=sum*i+tot;
        tot-=sum;
    }
    printf("%lld\n",-ans);
}
int main(){
    int t=1;//00;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/