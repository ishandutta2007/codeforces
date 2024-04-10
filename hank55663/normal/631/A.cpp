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
int mod=1e9+7;
bool solve(){
    int n;
    scanf("%d",&n);
    int a[10005],b[10005];
    int res1=0,res2=0;
    for(int i = 0;i<n;i++)scanf("%d",&a[i]),res1|=a[i];
    for(int i = 0;i<n;i++)scanf("%d",&b[i]),res2|=b[i];
 //   printf("%d %d\n",res1,res2);
    printf("%d\n",res1+res2);
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}