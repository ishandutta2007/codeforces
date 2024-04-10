#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
bool solve(){
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int tot=a[0]-1+a[1]-1+a[2]-1;
    sort(a,a+3);
    //tot%=9;
    if(tot%9==6&&tot/9<a[0])printf("Yes\n");
    else printf("No\n");
    return true;
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}