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
    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);
    int c[1005];
    int tot=0;
    for(int i = 0;i<m;i++)
        scanf("%d",&c[i]),tot+=c[i];
    tot+=(m+1)*(d-1);
    if(tot>=n){
        printf("YES\n");
        tot-=(m+1)*(d-1);
        int now=0;
        int less=d-1;
        for(int i=0;i<n;i++){
            if(tot==n-i){
                printf("%d ",now+1);
                c[now]--;
                if(c[now]==0)now++;
                tot--;
            }
            else if(less){
                printf("0 ");
                less--;
            }
            else{
                tot-=c[now];
                while(c[now]--)printf("%d ",now+1),i++;
                now++;
                i--;
                less=d-1;
            }
        }
        printf("\n");
    }
    else{
        printf("NO\n");
    }
}