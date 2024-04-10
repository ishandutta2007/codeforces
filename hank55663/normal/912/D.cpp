#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
LL cal(int x,int y,int n,int m,int r){
    LL Maxx=min(x,n-r+1),Minx=max(x-r+1,1);
    LL Maxy=min(y,m-r+1),Miny=max(y-r+1,1);
    return (Maxx-Minx+1)*(Maxy-Miny+1);
}
int main(){
    int n,m,r,k;
    scanf("%d %d %d %d",&n,&m,&r,&k);
    priority_queue<pair<int,pii>,vector<pair<int,pii> > ,less<pair<int,pii> > >pq;
    pq.push(mp(cal((n+1)/2,(m+1)/2,n,m,r),mp((n+1)/2,(m+1)/2)));
    LL tot = 0;
    set<pii> s;
    for(int i = 0;i<k;i++){
        tot+=pq.top().x;
        pii p =pq.top().y;
     //   printf("%d %d %d\n",pq.top().x,p.x,p.y);
        pq.pop();
        s.insert(p);
        int X[4]={0,0,1,-1};
        int Y[4]={1,-1,0,0};
        for(int i = 0;i<4;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>0&&x<=n&&y>0&&y<=m&&s.find(mp(x,y))==s.end()){
                pq.push(mp(cal(x,y,n,m,r),mp(x,y)));
                s.insert(mp(x,y));
            }
        }
    }
    printf("%.12lf\n",(double)tot/((LL)(n-r+1)*(m-r+1)));
}