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
    vector<pii> v;
    char c[5005];
    scanf("%s",c);
    v.pb(mp(0,0));
    int x=0,y=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='L')x--;
        if(c[i]=='R')x++;
        if(c[i]=='U')y++;
        if(c[i]=='D')y--;
        v.pb(mp(x,y));
    }
    for(auto it:v){
        x=0,y=0;
        for(int i = 0;c[i]!=0;i++){
            int orix=x,oriy=y;
            if(c[i]=='L')x--;
            if(c[i]=='R')x++;
            if(c[i]=='U')y++;
            if(c[i]=='D')y--;
            //v.pb(mp(x,y));
            if(mp(x,y)==it){
                x=orix;
                y=oriy;
            }
        }
        if(x==0&&y==0){
            printf("%d %d\n",it.x,it.y);
            return true;
        }
    }
    printf("0 0\n");
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