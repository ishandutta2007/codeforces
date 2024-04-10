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
#define MXN 1005
int go[1000005];
int vis[1000005];
void solve(){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[1000005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        go[i]=(i+d)%n;
    }
    fill(vis,vis+n+1,0);
    int Max=0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            int st=0;
            int first=1;
            int now=i;
            int cnt=0;
            do{
                if(a[now]==1)cnt++;
                else{
                    if(first)st=cnt,first=0;
                    Max=max(Max,cnt);
                    cnt=0;
                }
                vis[now]=1;
                now=go[now];
            }while(now!=i);
           // printf("%d %d\n",st,cnt);
            Max=max(Max,cnt+st);
            if(first){
                printf("-1\n");
                return;
            }
        }
    }
    printf("%d\n",Max);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*

*/