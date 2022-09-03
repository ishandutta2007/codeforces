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
#define MAXN 205
#define N 262144
int main(){
    int h1,h2;
    scanf("%d %d",&h1,&h2);
    int a,b;
    scanf("%d %d",&a,&b);
    h1+=a*8;
    if(h1>=h2){
        printf("0\n");
    }
    else{
        if(b>=a){
            printf("-1\n");
        }
        else{
            printf("%d\n",(h2-h1+12*a-12*b-1)/(12*a-12*b));
        }
    }
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/