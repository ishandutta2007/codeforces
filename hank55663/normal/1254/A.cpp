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
#define KK 500
#define N 100005
#define MXN 2000005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int R,C,k;
        scanf("%d %d %d",&R,&C,&k);
        char c[105][105];
        int tot=0;
        for(int i = 0;i<R;i++){
            scanf("%s",c[i]);
            for(int j=0;j<C;j++){
                if(c[i][j]=='R'){
                    tot++;
                }
            }
        }
        int need=tot/k;
        int bi=tot%k,small=k-tot%k;
        char ans[105][105];
        MEM(ans);
        int num=0;
        int tmp=0;
     //   printf("%d %d %d\n",need,bi,small);
        for(int i = 0;i<R;i++){
            if(i&1){
                for(int j=0;j<C;j++){
                    if(c[i][j]=='R')tmp++;
                    if(num<26)
                    ans[i][j]=num+'a';
                    else if(num<52)
                    ans[i][j]=num+'A'-26;
                    else
                    ans[i][j]=num+'0'-52;
                    if(bi==0&&tmp==need){
                        tmp=0;
                        num++;
                    }
                    else if(tmp==need+1&&bi){
                        bi--;
                        num++;
                        tmp=0;
                    }
                    if(num>=k)
                    num=k-1;
                }
               
            }
            else{
                for(int j=C-1;j>=0;j--){
                    if(c[i][j]=='R')tmp++;
                    if(num<26)
                    ans[i][j]=num+'a';
                    else if(num<52)
                    ans[i][j]=num+'A'-26;
                    else
                    ans[i][j]=num+'0'-52;
                    if(bi==0&&tmp==need){
                        num++;
                        tmp=0;
                    }
                    else if(tmp==need+1&&bi){
                        bi--;
                        num++;
                        tmp=0;
                    }
                    if(num>=k)
                    num=k-1;
                }
                
            }
            printf("%s\n",ans[i]);
        }
    }
    return 0;
}