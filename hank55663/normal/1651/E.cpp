#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 2005
vector<int> v[3005];
int vis[3005];
vector<int> stk;
void dfs(int x,int f){
    if(stk.size()&&x==stk[0])return;
    stk.pb(x);
    vis[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            break;
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<2*n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    LL ans=0;
    for(int i = 2;i<=2*n;i++){
        if(!vis[i]){
            dfs(i,0);
            int nn=stk.size();
            for(int i = 0;i<=nn;i++)stk.pb(stk[i]);
           // for(auto it:stk)printf("%d ",it);
          //  printf("??\n");
           /* int sum=0;
            for(int a = 1;a<=n;a++){
                for(int b = a;b<=n;b++){
                    for(int c=n+1;c<=2*n;c++){
                        for(int d=c;d<=2*n;d++){
                            int st=-1;
                            int cnt=0;
                            for(int j=0;j<nn;j++){
                                if(stk[j]>=a&&stk[j]<=b){
                                    cnt++;
                                }
                                else if(stk[j]>=c&&stk[j]<=d){
                                    cnt++;
                                }
                                else{
                                    if(st==-1)st=cnt;
                                    else sum+=cnt/2;
                                    cnt=0;
                                }
                            }
                            if(st==-1)sum+=cnt/2;
                            else
                            sum+=(st+cnt)/2;
                             // printf("%d %d %d %d %d\n",a,b,c,d,sum);
                        }
                    }
                }
            }*/
          //  printf("%d\n",sum);
            for(int i = 1;i<=nn;i++){
                int Maxa=0,Mina=1e9;
                int Maxb=0,Minb=1e9;
                for(int j = i;j<i+nn-1;j++){
                    if(stk[j]<=n)Maxa=max(Maxa,stk[j]),Mina=min(Mina,stk[j]);
                    else Maxb=max(Maxb,stk[j]),Minb=min(Minb,stk[j]);
                    int la=Mina,ra=n-Maxa+1;
                    int lb=Minb-n,rb=2*n-Maxb+1;
                    if(stk[j+1]<=n){
                        if(stk[j+1]<Mina)la=min(Mina-stk[j+1],la);
                        else if(stk[j+1]>Maxa)ra=min(stk[j+1]-Maxa,ra);
                        else continue;
                    }
                    else{
                        if(stk[j+1]<Minb)min(lb=Minb-stk[j+1],lb);
                        else if(stk[j+1]>Maxb)rb=min(stk[j+1]-Maxb,rb);
                        else continue;
                    }
                     if(stk[i-1]<=n){
                        if(stk[i-1]<Mina)la=min(Mina-stk[i-1],la);
                        else if(stk[i-1]>Maxa)ra=min(stk[i-1]-Maxa,ra);
                        else continue;
                    }
                    else{
                        if(stk[i-1]<Minb)lb=min(lb,Minb-stk[i-1]);
                        else if(stk[i-1]>Maxb)rb=min(stk[i-1]-Maxb,rb);
                        else continue;
                    }
                   // printf("%d %d %d %d %d %d %d %d %d %d\n",Mina,Maxa,Minb,Maxb,la,ra,lb,rb,stk[j+1],stk[i-1]);
                    ans+=ra*1ll*la*rb*lb*((j-i+1)/2);
                }
                if(i==1){
                    int j=nn;
                    if(stk[j]<=n)Maxa=max(Maxa,stk[j]),Mina=min(Mina,stk[j]);
                    else Maxb=max(Maxb,stk[j]),Minb=min(Minb,stk[j]);
                    int la=Mina,ra=n-Maxa+1;
                    int lb=Minb-n,rb=2*n-Maxb+1;
                     //  printf("%lld\n",ans);
                    //  printf("%d %d %d %d %d %d %d %d %d\n",Mina,Maxa,Minb,Maxb,la,ra,lb,rb);
                    ans+=ra*1ll*la*rb*lb*(nn/2);
                   //   printf("%lld\n",ans);
                }
            }
          //  printf("%lld\n",ans);
            stk.clear();

        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
   //   scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/