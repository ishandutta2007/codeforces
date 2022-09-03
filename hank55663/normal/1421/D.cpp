#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int x,y;
    scanf("%d %d",&x,&y);
    int c[7];
    for(int i = 1;i<=6;i++)scanf("%d",&c[i]);
    int X[7]={0,1,0,-1,-1,0,1};
    int Y[7]={0,1,1,0,-1,-1,0};
    LL a[3][3];
    for(int i = 0;i<3;i++){
        for(int j =0;j<3;j++){
            a[i][j]=1e18;
        }
    }
    a[1][1]=0;
    queue<pii> q;
    q.push(mp(1,1));
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i = 1;i<=6;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=0&&x<3&&y>=0&&y<3&&a[x][y]>a[p.x][p.y]+c[i]){
                a[x][y]=a[p.x][p.y]+c[i];
                q.push(mp(x,y));
            }
        }
    }
    int d=min(abs(x),abs(y));
    LL ans=0;
    if(x>0&&y>0){
        ans+=a[2][2]*d;
    }
    else if(x<0&&y<0){
        ans+=a[0][0]*d;
    }
    else if(x>0&&y<0){
        ans+=a[2][0]*d;
    }
    else if(x<0&&y>0){
        ans+=a[0][2]*d;
    }
    if(abs(x)>abs(y)){
        int need=abs(x)-abs(y);
        if(x>0)ans+=a[2][1]*need;
        else ans+=a[0][1]*need;
    }
    else if(abs(y)>abs(x)){
        int need=abs(y)-abs(x);
        if(y>0)ans+=a[1][2]*need;
        else ans+=a[1][0]*need;
    }
    printf("%lld\n",ans);
    //c[1]=min(c[2]+c[6],c[1]);
    //c[4]=min(c[3]+c[5],c[4]);

}



int main(){
    int t=1;
    scanf("%d",&t);
   
    while(t--){
        solve();
    }
}
/*
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/