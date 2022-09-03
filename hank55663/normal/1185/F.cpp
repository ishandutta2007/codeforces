#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii price[3005];
    int cnt[3005];
    int tot[3005];
    vector<pii> vv[3005];
    MEM(cnt);
    fill(price,price+3005,mp(2000000000,2000000000));
    MEM(tot);
    for(int i = 0;i<n;i++){
        int num=0;
        int t;
        scanf("%d",&t);
        while(t--){
            int x;
            scanf("%d",&x);
            x--;
            num|=(1<<x);
        }
        cnt[num]++;
    }
    for(int i = 0;i<(1<<9);i++){
        for(int j =0;j<(1<<9);j++){
            if((i&j)==j){
                tot[i]+=cnt[j];
            }
           // if(cnt[j])printf("%d %d\n",cnt[j],j);
        }
      //  if(tot[i])printf("%d %d\n",i,tot[i]);
    }
    for(int i = 0;i<m;i++){
        int num=0;
        int t,cost;
        scanf("%d %d",&cost,&t);
        while(t--){
            int x;
            scanf("%d",&x);
            x--;
            num|=(1<<x);
        }
        price[num]=min(price[num],mp(cost,i+1));
        vv[num].pb(mp(cost,i+1));
      //  printf("%d\n",num);
    }
    int ansnum=0,ansp=2e9+1,ansa,ansb;
    for(int i = 0;i<(1<<9);i++){
        for(int j = i+1;j<(1<<9);j++){
            if(price[i].x==2e9||price[j].x==2e9)continue;
            int num=i|j;
            if(tot[num]>ansnum){
                ansnum=tot[num];
                ansp=price[i].x+price[j].x;
                ansa=price[i].y;
                ansb=price[j].y;
            }
            if(tot[num]==ansnum&&ansp>price[i].x+price[j].x){
                ansp=price[i].x+price[j].x;
                ansa=price[i].y;
                ansb=price[j].y;
            }
        }
        sort(vv[i].begin(),vv[i].end());
        if(vv[i].size()>=2){
            int num=i;
            if(tot[num]>ansnum){
                ansnum=tot[num];
                ansp=vv[i][0].x+vv[i][1].x;
                ansa=vv[i][0].y;
                ansb=vv[i][1].y;
            }
            if(tot[num]==ansnum&&ansp>vv[i][0].x+vv[i][1].x){
                ansnum=tot[num];
                ansp=vv[i][0].x+vv[i][1].x;
                ansa=vv[i][0].y;
                ansb=vv[i][1].y;
            }
        }
    }
    //printf("%d %d\n",ansnum,ansp);
    printf("%d %d\n",ansa,ansb);
}
/*
m3->m2->m->m4
0 1 2 3 4
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/