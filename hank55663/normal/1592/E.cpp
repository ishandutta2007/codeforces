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
vector<int> q[1048576];
int now[1048576];
void solve(){
    //printf("%d\n",sizeof(q));
    int n;
    scanf("%d",&n);
    int a[1000005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i = 0;i<20;i++){
        for(int j = 0;j<1048576;j++){
            q[j].clear();
            now[j]=0;
        }
        int sum=0;
        int l=0;
        q[0].pb(0);
        for(int j = 1;j<=n;j++){
            sum^=a[j];
            if(a[j]&1);
            else{
                l=j;
            }
            while(q[sum].size()!=now[sum]&&q[sum][now[sum]]<l)now[sum]++;
            if(q[sum].size()!=now[sum]){
                ans=max(ans,j-q[sum][now[sum]]);
            }
            q[sum].pb(j);
        }
        for(int j=1;j<=n;j++)a[j]>>=1;
    }
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/