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
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
bool solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    set<int> X,Y;
    map<int,set<int> > XX,YY;
    pii p[100005],p2[100005];
    set<pii> s;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        p2[i]=mp(y,x);
        s.insert(mp(x,y));
         XX[x].insert(y);
        YY[y].insert(x);
    }
    sort(p,p+n);
    sort(p2,p2+n);
    int nowx=0,nowy=0;
    X.insert(1e9+9);
    Y.insert(1e9+9);
    map<int,int> m;
    int now1=0,now2=0;
    while(nowx<1e9+7&&nowy<1e9+7){
        while(now1!=n&&nowx>=p[now1].x){
            Y.insert(p[now1].y);
          //  printf("add Y %d\n",p[now1].y);
            now1++;
        }
        while(now2!=n&&nowy>=p2[now2].x){
          //  printf("add X %d\n",p[now2].y);
            X.insert(p2[now2].y);
            now2++;
        }
       // printf("? %d %d\n",nowx,nowy);
        while(*X.lower_bound(nowx)==nowx)nowx++;
        while(*Y.lower_bound(nowy)==nowy)nowy++;
         while(now1!=n&&nowx>=p[now1].x){
            Y.insert(p[now1].y);
           // printf("add Y %d\n",p[now1].y);
            now1++;
        }
        while(now2!=n&&nowy>=p2[now2].x){
            //printf("add X %d\n",p[now2].y);
            X.insert(p2[now2].y);
            now2++;
        }
        int d1=*X.lower_bound(nowx)-nowx;
        int d2=*Y.lower_bound(nowy)-nowy;
        int d3;
        if(now1==n)d3=1e9+25;
        else d3=p[now1].x-nowx;
        int d4;
        if(now2==n)d4=1e9+25;
        else d4=p2[now2].x-nowy;
        int d=min(min(d1,d2),min(d3,d4));
       // printf("%d %d %d %d %d %d\n",d1,d2,d3,d4,nowx,nowy);
       // getchar();
        if(d==0)continue;
        else{
            m[nowx]=nowy-nowx;
           // printf("%d %d\n",nowx,nowy);
            nowx+=d;
            nowy+=d;
        }
        
    }
    for(int i = 0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(s.find(mp(x,y))!=s.end()){
            printf("LOSE\n");
        }
        else if(XX.find(x)!=XX.end()&&XX[x].lower_bound(y)!=XX[x].begin()){
            printf("WIN\n");
        }
        else if(YY.find(y)!=YY.end()&&YY[y].lower_bound(x)!=YY[y].begin()){
            printf("WIN\n");
        }
        else{
            if(m.upper_bound(x)==m.begin()){
                printf("WIN\n");
            }
            else{
                auto it=prev(m.upper_bound(x));
                if(y-x==it->y)printf("LOSE\n");
                else printf("WIN\n");
                /*
                x-=X.order_of_key(x);
                y-=Y.order_of_key(y);
                if(x==y)printf("LOSE\n");
                else printf("WIN\n");*/
            }
        }
    }
}
int main(){
    int t=1;
  //  scanf("%d",&t);
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