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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
int cnt[100005];
char a[100005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        fill(cnt,cnt+n+1,0);
        scanf("%s",a+1);
        for(int i = 1;i<=n;i++){
            if(a[i]=='1')cnt[i]=cnt[i-1]-1;
            else cnt[i]=cnt[i-1]+1;
        }     
        if(cnt[n]==0){
            int ok=0;
            for(int i = 0;i<=n;i++){
                if(cnt[i]==x){
                    printf("-1\n");
                    ok=1;
                    break;
                }
            }
            if(!ok){
                printf("0\n");
            }
        }
        else{
            int ans=0;
            for(int i=0;i<n;i++){
               // printf("%d %d %d\n",x,cnt[i],cnt[n]);
                if((x-cnt[i])%cnt[n]==0&&(x-cnt[i])/cnt[n]>=0){
                    
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
}