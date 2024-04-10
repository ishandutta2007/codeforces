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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
#define index Index
int main(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    int sum=0;
    int tmp=1;
    for(int i = 1;i<=l;i++){
        sum+=tmp;
        tmp<<=1;
    }
    printf("%d ",sum+(n-l)*1);
    for(int i = l+1;i<r;i++){
        sum+=tmp;
        tmp<<=1;
    }
    if(l!=r)
    printf("%d\n",sum+(n-r+1)*tmp);
    else{
printf("%d\n",sum+(n-r)*tmp/2);
    }
}

/*
7
A B son of C
A C son of D
A D son of B
A E son of B
A F son of C
A G son of D
A H son of E
*/