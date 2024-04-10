#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int Next[200005][10];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[200005];
        scanf("%s",c);
        int n=strlen(c);
        int cnt[10];
        fill(cnt,cnt+10,0);
        for(int i = 0;c[i]!=0;i++)cnt[c[i]-'0']++;
        for(int i=0;i<10;i++)
        Next[n][i]=n;
        for(int i = n-1;i>=0;i--){
            for(int j=0;j<10;j++)Next[i][j]=Next[i+1][j];
             //for(int j=0;j<10;j++)printf("%d ",Next[i][j]);
            //printf("\n");
            Next[i][c[i]-'0']=i;
            //for(int j=0;j<10;j++)printf("%d ",Next[i][j]);
            //printf("\n");
        }
        //printf("?\n");
       // getchar();
        //getchar();
        int ans=0;
        //for(int i =0;i<10;i++)ans=max(ans,cnt[i]);
        for(int i = 0;i<10;i++){
            for(int j =0;j<10;j++){
                int now=0;
                int k=0;
                while(now<n){
                    if(k&1)now=Next[now][i]+1;//printf("%d %d\n",now,Next[now][i]);
                    else now=Next[now][j]+1;//printf("%d %d\n",now,Next[now][j]);
                    k++;
                    //printf("%d\n",now);
                }
                if(now!=n)k--;
                if(i!=j&&(k%2==1))k--;
                ans=max(ans,k);
            }
        }
        printf("%d\n",n-ans);
    }
}