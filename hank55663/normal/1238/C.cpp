#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int h,n;
        scanf("%d %d",&h,&n);
        int x[200005];
        for(int i = 0;i<n;i++)
        scanf("%d",&x[i]);
        x[n]=0;
        int ans=0;
        for(int i = 0;i<n;i++){
           // printf("i:%d\n",i);
            if(x[i+1]==x[i+2]+1||x[i+1]==0)i++;
            else{
            //    printf("%d\n",i);
                ans++;
                //i++;
            }
        }
        printf("%d\n",ans);
    }
}