#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL Ans=0;
void dfs(int last,int sum,int d){
    Ans++;
    //printf("%d %d\n",last,sum);
    for(int i = last+1;i<=d;i++){
        if((sum^i)>sum){
            dfs(i,sum^i,d);
        }
    }
}
int main(){
   // int t;
  //  scanf("%d",&t);
   // while(t--){
 //       int d,m;
//        scanf("%d %d",&d,&m);
    /*map<int,int> s;
    ans=1;
     for(int d=1;d<=50;d++){
        LL tmp=ans-1;
        ans=0;
        dfs(0,0,d);
        printf("%lld %lld\n",ans-1,ans-1-tmp);
        s[ans-1-tmp]++;
     }
     LL last=1;
     for(auto it:s){
         printf("%lld %lld\n",it.x/last,it.y);
         last=it.x;
     }*/
    //}
    int t;
    scanf("%d",&t);
    while(t--){
        int m,d;
        scanf("%d %d",&d,&m);
        if(d==1){
            printf("%d\n",1%m);
            continue;
        }
        int td=d;
        LL now=2,Next=1,last=2,ans=1;
        d--;
        for(int i = 2;d;i<<=1){
            LL add=min(d,i);
            ans=ans+now*add;
            ans%=m;
            last+=Next;
            last%=m;
            now*=last;
            now%=m;
            Next<<=1;
            Next%=m;
            d-=add;
        }
        printf("%lld\n",ans);
       /* Ans=0;
        dfs(0,0,td);
        printf("%lld\n",Ans);
        assert(ans==(Ans-1)%m);*/
    }
}
/*

*/