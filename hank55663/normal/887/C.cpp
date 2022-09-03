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
int a[25];
int cnt[6][8]={{1,3,5,7,9,11,24,22},{2,4,6,8,10,12,23,21},{13,14,5,6,17,18,21,22},{15,16,7,8,19,20,23,24},{3,4,17,19,10,9,16,14},{1,2,18,20,12,11,15,13}};
int main(){
    for(int i = 1;i<=24;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<6;i++){
        for(int tt=0;tt<2;tt++)
            for(int j = 0;j<7;j++){
                swap(a[cnt[i][j]],a[cnt[i][j+1]]);
            }
        int ok=1;
        for(int j=0;j<6;j++){
            if(a[j*4+1]==a[j*4+2]&&a[j*4+2]==a[j*4+3]&&a[j*4+3]==a[j*4+4]);
            else ok=0;
            //printf("%d %d %d %d\n",a[j*4+1],a[j*4+2],a[j*4+3],a[j*4+4]);
        }
      //  printf("\n");
        if(ok){
            printf("YES\n");
            return 0;
        }
        for(int tt=0;tt<2;tt++){
            for(int j=6;j>=0;j--){
                swap(a[cnt[i][j+1]],a[cnt[i][j]]);
            }
        }
    }
    printf("NO\n");
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/