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
int vis[200005];
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a<200005){
            vis[a]++;
        }
    }
    vector<int> v;
    for(int i = 1;i<=200000;i++){
        if(i>m)break;
        if(!vis[i]){
            m-=i;
            v.pb(i);
        }
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d ",it);
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}