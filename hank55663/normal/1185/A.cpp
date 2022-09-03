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
int main(){
    int a[3],d;
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&d);
    sort(a,a+3);
    int ans=max(d-(a[2]-a[1]),0)+max(d-(a[1]-a[0]),0);
    printf("%d\n",ans);
}
/*
m3->m2->m->m4
0 1 2 3 4
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/