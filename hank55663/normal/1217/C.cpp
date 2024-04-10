#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 15000

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[200005];
        scanf("%s",c+1);
        int last[200005];
        last[1]=0;
        for(int i =2;c[i]!=0;i++){
            if(c[i-1]=='1')last[i]=i-1;
            else last[i]=last[i-1];
        }
        LL ans=0;
        for(int i = 1;c[i]!=0;i++){
            int k=0;
            int now=0;
            while(true){
                if(c[i-k]=='1'){
                    if(k>=30)
                    now+=1e9;
                    else
                    now+=(1<<k);
                }
                int la=last[i-k];
                if(now<=i-la&&now>k)ans++;
                //printf("%d %d %d %d %d\n",now,i-la,k,i,ans);
                k=i-la;
                if(k>=i||now>=i)break;
                //printf("%d %d\n",k,i);
                //getchar();
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}