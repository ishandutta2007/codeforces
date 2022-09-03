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
pii p[200005];
int val[400005];
int Size=500;
int cnt[505][505];
int st[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    int ans=0;
    for(int i = 1;i<=m;i++){
        ans+=val[i];
        int op,k;
        scanf("%d %d",&op,&k);
        if(op==1){
            if(p[k].x+p[k].y>=Size){
                st[k]=i;
                for(int j = i+p[k].x;j<=m;j+=p[k].x+p[k].y){
                    val[j]++;
                    if(j+p[k].y<=m)val[j+p[k].y]--;
                }
            }
            else{
                st[k]=i;
                int mod=p[k].x+p[k].y;
                for(int j = i;j<i+p[k].x+p[k].y;j++){
                    if(j<i+p[k].x);
                    else cnt[mod][j%mod]++;
                }
            }
        }
        else{
            if(p[k].x+p[k].y>=Size){
                for(int j = st[k]+p[k].x;j<=m;j+=p[k].x+p[k].y){
                    val[j]--;
                    if(i>=j&&i<j+p[k].y)ans--;
                    if(j+p[k].y<=m)val[j+p[k].y]++;
                }
            }
            else{
                int mod=p[k].x+p[k].y;
                for(int j = st[k];j<st[k]+p[k].x+p[k].y;j++){
                    if(j<st[k]+p[k].x);
                    else cnt[mod][j%mod]--;
                }
            }
        }
        int res=ans;
        for(int j = 1;j<=500;j++)res+=cnt[j][i%j];
        printf("%d\n",res);
    }
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