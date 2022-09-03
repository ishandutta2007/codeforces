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
bool solve(){
    int n[3];//,n2,n3;
    scanf("%d %d %d",&n[0],&n[1],&n[2]);
    vector<int> v[3];
    LL ans=0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<n[i];j++){
            int x;
            scanf("%d",&x);
            v[i].pb(x);
            ans+=x;
        }
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());
    LL Min=min(v[0][0]+v[1][0],min(v[1][0]+v[2][0],v[0][0]+v[2][0]));
    for(int i = 0;i<3;i++){
        LL sum=0;
        for(auto it:v[i])sum+=it;
        Min=min(Min,sum);
    }
    printf("%lld\n",ans-2*Min);
}
int main(){
    int t=1;//00000;
 //   scanf("%d",&t);
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