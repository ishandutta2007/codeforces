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
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    a--;
    a+=b;
    a=(a%n+n)%n;
    printf("%d\n",a+1);
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}