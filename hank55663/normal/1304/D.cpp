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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[200005];
        scanf("%s",c);
        int num[200005];
        int now=1;
        int cnt=1;
        now=n;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='>'){
                for(int j=1;j<=cnt;j++){
                    printf("%d ",now-cnt+j);
                }
                now-=cnt;
                cnt=1;
                
            }
            else{
                cnt++;
            }
        }
        for(int j=1;j<=cnt;j++){
            printf("%d ",now-cnt+j);
        }
        printf("\n");
        now = 1;
        for(int i = 0 ; c[i] != 0 ; i++){
            if(c[i]=='<'){
                num[i]=now++;
            }
        }
        num[n-1]=now++;
        for(int i = n-2;i>=0;i--){
            if(c[i]=='>'){
                num[i]=now++;
            }
        }
        for(int i = 0;i<n;i++){
            printf("%d ",num[i]);
        }
        printf("\n");
        
    }
}
/*
6 10
1 1 0 0 0 0 0 0 0 0 
1 1 1 1 0 0 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 
2 2 3 3 0 0 0 0 0 0 
0 0 3 3 4 4 0 0 0 0 

{1}
{1}
{1000000000}
{1000000000}
1

1000000000 
1000
{1000}
{1000000000}
*/