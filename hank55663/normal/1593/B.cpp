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
void solve(){
    char c[100];
    scanf("%s",c);
    reverse(c,c+strlen(c));
    int ans=1e9;
    int sum=0;
    char x[10]="2570",y[10]="5050";
    for(int t=0;t<4;t++){
    for(int i = 0;c[i]!=0;i++){
        if(c[i]==y[t]){
         //   printf("%d %d %c\n",i,t,x[t]);
            for(int j = i+1;c[j]!=0;j++){
                if(c[j]==x[t]){
                   //  printf("%d %d %c!\n",j,t,y[t]);
                    ans=min(ans,sum);
                    break;
                }
                sum++;
            }
            break;
        }
        sum++;
    }
    sum=0;
    }
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/