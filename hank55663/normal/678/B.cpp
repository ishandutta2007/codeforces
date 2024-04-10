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
int leap(int y){
    return y%4==0&&(y%400==0||y%100!=0);
}
int main(){
    int y;
    scanf("%d",&y);
    int now=0;
    if(leap(y))now+=2;
    else now++;
    for(int i = y+1;;i++){
        if(now%7==0&&leap(y)==leap(i)){
            printf("%d\n",i);
            break;
        }
        if(leap(i))now+=2;
        else now++;
    }
}
/*

*/