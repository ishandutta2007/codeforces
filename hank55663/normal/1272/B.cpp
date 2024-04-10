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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int cnt[4]={0,0,0,0};
        char c[100005];
        scanf("%s",c);
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='L')cnt[0]++;
            if(c[i]=='R')cnt[1]++;
            if(c[i]=='U')cnt[2]++;
            if(c[i]=='D')cnt[3]++;
        }
        int x=min(cnt[2],cnt[3]);
        cnt[2]=cnt[3]=x;
        int y=min(cnt[0],cnt[1]);
        cnt[0]=cnt[1]=y;
        if(cnt[0]&&cnt[2]){
            printf("%d\n",cnt[0]+cnt[1]+cnt[2]+cnt[3]);
            for(int i = 0;i<cnt[0];i++)printf("L");
            for(int i =0;i<cnt[2];i++)printf("U");
            for(int i = 0;i<cnt[0];i++)printf("R");
            for(int i =0;i<cnt[2];i++)printf("D");
            printf("\n");
        }
        else if(cnt[0]){
            printf("2\nLR\n");
        }
        else if(cnt[2]){
            printf("2\nUD\n");
        }
        else{
            printf("0\n\n");
        }
    }
}