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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
bool solve(){
    int n;
    scanf("%d",&n);
    vector<pii> v;
    //for(int i = n;i>=3;i--)v.pb(mp(i,i-1));
    int a[200005];
    for(int i = 1;i<=n;i++)a[i]=i;
    for(int i = n-1;i>=3;i--){
        while((a[n]+a[i]-1)/a[i]>=a[i]){
            a[n]=(a[n]+a[i]-1)/a[i];
            v.pb(mp(n,i));
        }
        v.pb(mp(i,n));
        a[i]=(a[i]+a[n]-1)/a[n];
    }
    while(a[n]!=1){
        v.pb(mp(n,2));
        a[n]=(a[n]+a[2]-1)/a[2];
    }
    printf("%d\n",v.size());
    for(auto it:v)printf("%d %d\n",it.x,it.y);
    for(int i = 3;i<=n;i++)assert(a[i]==1);//printf("%d ",a[i]);
    //printf("\n");
    return true;
}
int main(){
    int t=1;00000;//0000;//00000;//000000;//000000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/