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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int len[3]={y,y,y};
    for(int i=1;;i++){
        int tot=len[0]+len[1]+len[2];
        len[i%3]=min(tot-len[i%3]-1,x);
        if(len[0]==len[1]&&len[1]==len[2]&&len[2]==x){
            printf("%d\n",i);
            return 0;
        }
    }
}