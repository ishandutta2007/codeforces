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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[1000005];
    scanf("%s",c);
    int Maxx=0,Minx=0,Maxy=0,Miny=0;
    int x=0,y=0;
    int lastx=1,lasty=1;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='R')y++;
        else if(c[i]=='L')y--;
        else if(c[i]=='D')x++;
        else x--;
        Maxx=max(Maxx,x);
        Maxy=max(Maxy,y);
        Minx=min(Minx,x);
        Miny=min(Miny,y);
        if(Maxx-Minx+1>n||Maxy-Miny+1>m){
            printf("%d %d\n",lastx,lasty);
            return;
        }
        lastx=-Minx+1;
        lasty=-Miny+1;
    }
    printf("%d %d\n",lastx,lasty);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/