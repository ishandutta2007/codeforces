#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define read(x) scanf("%d",&x);
#define min(x,y) (((x)<(y))?(x):(y))
using namespace std;
vector<int>a[4];
int n,x;
int main(){
    read(n);rep(i,1,n){read(x);a[x].push_back(i);}x=100000;
    rep(i,1,3)x=min(x,a[i].size());printf("%d\n",x);
    rep(i,0,x-1)printf("%d %d %d\n",a[1][i],a[2][i],a[3][i]);
}