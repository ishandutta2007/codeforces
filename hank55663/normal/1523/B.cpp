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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    //printf("?\n");
    vector<pair<int,pii> > v;
    for(int i = 1;i<=n;i+=2){
        v.pb(mp(1,mp(i,i+1)));//a+b b
        v.pb(mp(2,mp(i,i+1)));//a+b -a
        v.pb(mp(1,mp(i,i+1)));//b -a
        v.pb(mp(1,mp(i,i+1)));//-a+b -a
        v.pb(mp(2,mp(i,i+1)));//-a+b -b
        v.pb(mp(1,mp(i,i+1)));//-a -b;
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d %d\n",it.x,it.y.x,it.y.y);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/