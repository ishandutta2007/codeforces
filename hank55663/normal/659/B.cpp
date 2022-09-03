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
vector<pair<int,string> > v[10005];
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        char c[105];
        int a,b;
        scanf("%s %d %d",c,&a,&b);
        v[a].pb(mp(b,string(c)));
    }
    for(int i = 1;i<=m;i++){
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        if(v[i].size()>=3&&v[i][1].x==v[i][2].x){
            printf("?\n");
        }
        else{
            printf("%s %s\n",v[i][0].y.c_str(),v[i][1].y.c_str());
        }
    }
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}