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
bool cmp(const pair<pii,int> &p,const pair<pii,int> &q){
    if(p.x.x==q.x.x)return p.x.y>q.x.y;
    else return p.x.x<q.x.x;
}
bool solve(){
    int n;
    scanf("%d",&n);
    int ans[200005];
    fill(ans,ans+n+1,-1);
    vector<pair<pii,int> > v;
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.pb(mp(mp(x,y),i));
        v.pb(mp(mp(y,x),i));
    }
    sort(v.begin(),v.end(),cmp);
    map<int,int> m;
    for(auto it:v){
        m[it.x.y]=it.y;
       // printf("%d %d\n",it.x.y,it.y);
        if(m.find(it.x.y)!=m.begin()){
            ans[it.y]=prev(m.find(it.x.y))->y;
           // printf("?%d %d\n",prev(m.find(it.x.y))->x,prev(m.find(it.x.y))->y);
        }   
    }
    for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return true;
}
int main(){
    int t=1;00000;
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