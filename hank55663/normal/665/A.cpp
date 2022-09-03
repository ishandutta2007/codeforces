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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int main(){
    int a,at;
    int b,bt;
    int h,m;
    scanf("%d %d %d %d %d:%d",&a,&at,&b,&bt,&h,&m);
    int ti=h*60+m-300-bt,ti2=min(h*60+m-300+at-1,1139);
    //printf("%d %d\n",ti,ti2);

    if(ti<0){
        printf("%d\n",ti2/b+1);
    }
    else
    printf("%d\n",ti2/b-ti/b);
}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/