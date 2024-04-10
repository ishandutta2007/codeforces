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
    LL x,y;
    scanf("%lld %lld",&x,&y);
    if(x==y){
        printf("YES\n");
        return ;
    }
    vector<int> vx,vy;
    while(x)vx.pb(x&1),x>>=1;
    while(y)vy.pb(y&1),y>>=1;
  /*  for(auto it:vx)printf("%d",it);
    printf("\n");
    for(auto it:vy)printf("%d",it);
    printf("\n");*/
    reverse(vx.begin(),vx.end());
    vx.pb(1);
    for(int i = 0;i+vx.size()-1<vy.size();i++){
            
            int ok=1;
            for(int j = 0;j<vx.size();j++){
                if(vx[j]!=vy[i+j])ok=0;//printf("%d %d\n",vx[j],vy[i+j]);
            }
           // printf("%d\n",ok);
            for(int j = i+vx.size();j<vy.size();j++){
                if(vy[j]!=1)ok=0;
            }
            if(ok){
                printf("YES\n");
                return;
            }
            if(vy[i]==0)break;
        }
        vx.pop_back();
           reverse(vx.begin(),vx.end());
    for(int t=1;t>=0;t--){
        if((t==0)||(t==1&&vy[0]==1))
        for(int i = t;i+vx.size()-1<vy.size();i++){
            
            int ok=1;
            for(int j = 0;j<vx.size();j++){
                if(vx[j]!=vy[i+j])ok=0;//printf("%d %d\n",vx[j],vy[i+j]);
            }
          //  printf("%d\n",ok);
            for(int j = i+vx.size();j<vy.size();j++){
                if(vy[j]!=1)ok=0;
            }
            if(ok){
                printf("YES\n");
                return;
            }
            if(vy[i]==0)break;
        }
        reverse(vx.begin(),vx.end());
        while(vx.back()==0)vx.pop_back();
        reverse(vx.begin(),vx.end());
    }
    reverse(vx.begin(),vx.end());
    for(int i = 0;i+vx.size()-1<vy.size();i++){
            
            int ok=1;
            for(int j = 0;j<vx.size();j++){
                if(vx[j]!=vy[i+j])ok=0;//printf("%d %d\n",vx[j],vy[i+j]);
            }
           // printf("%d\n",ok);
            for(int j = i+vx.size();j<vy.size();j++){
                if(vy[j]!=1)ok=0;
            }
            if(ok){
                printf("YES\n");
                return;
            }
            if(vy[i]==0)break;
        }
    printf("NO\n");
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/