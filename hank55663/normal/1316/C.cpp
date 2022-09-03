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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005


LL a[1000005],b[1000005];
LL myrand(){
    return (((LL)rand()<<16)+rand());
}
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    vector<int> va,vb;
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]%p)va.pb(i);
    }
    for(int i = 0;i<m;i++){
        scanf("%lld",&b[i]);
        if(b[i]%p)vb.pb(i);
    }
    printf("%d\n",va[0]+vb[0]);
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/