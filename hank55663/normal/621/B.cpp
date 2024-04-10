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
#define N 1000000

bool solve(){;
    int n;
    scanf("%d",&n);
    map<int,LL> m1,m2;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        m1[x+y]++;
        m2[x-y]++;
    }
    LL ans=0;
    for(auto it:m1){
        ans+=it.y*(it.y-1)/2;
    }
    for(auto it:m2){
        ans+=it.y*(it.y-1)/2;
    }
    printf("%lld\n",ans);
    return true;
}
int main(){
    int t=1;00000;
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