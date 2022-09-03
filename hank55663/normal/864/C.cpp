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
    int a,b,f,k;
    scanf("%d %d %d %d",&a,&b,&f,&k);
    if(b<f||b<a-f){
        printf("-1\n");
        return 0;
    }
    int gas=b,gas2=b;
    int ans=0;
    for(int i = 0;i<k;i++){
        gas-=f;
        gas2-=f;
        if(gas<0){
            if(gas2<0){
                printf("-1\n");
                return 0;
            }
            gas=gas2;
            ans++;
        }
        gas2=b;
        gas-=a-f;
        gas2-=a-f;
        if(gas<0){
            if(gas2<0){
                printf("-1\n");
                return 0;
            }
            gas=gas2;
            ans++;
        }
        i++;
        if(i==k){
            break;
        }
        gas-=a-f;
        gas2-=a-f;
        if(gas<0){
            if(gas2<0){
                printf("-1\n");
                return 0;
            }
            gas=gas2;
            ans++;
          //  gas2=b;
        }
        gas2=b;
        gas-=f;
        gas2-=f;
        if(gas<0){
            if(gas2<0){
                printf("-1\n");
                return 0;
            }
            gas=gas2;
            ans++;
        }
       // printf("%d\n",ans);
    }
    printf("%d\n",ans);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/