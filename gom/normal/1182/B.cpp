#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
//typedef tuple<int,int,int> TP;
typedef tuple<int,int,int,int> TP;
const int N=505;
const ll MOD=1e9+7;
int w,h,x,y,sx,ex,sy,ey,a[N][N],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
string s;
void err()
{
    cout<<"NO";
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        cin>>s;
        for(int j=1;j<=w;j++) if(s[j-1]=='*') a[i][j]=1;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            bool ok=true;
            for(int k=0;k<4;k++){
                if(i+dx[k]<=0||i+dx[k]>h||j+dy[k]<=0||j+dy[k]>w) ok=false;
                if(!a[i+dx[k]][j+dy[k]]) ok=false;
            }
            if(!a[i][j]) ok=false;
            if(ok&&x) err();
            if(ok){
                x=i; y=j;
            }
        }
    }
    for(int i=1;i<=h;i++) if(!sx&&a[i][y]) sx=i;
    for(int i=h;i>=1;i--) if(!ex&&a[i][y]) ex=i;
    for(int j=1;j<=w;j++) if(!sy&&a[x][j]) sy=j;
    for(int j=w;j>=1;j--) if(!ey&&a[x][j]) ey=j;
    for(int i=sx;i<=ex;i++) if(!a[i][y]) err();
    for(int j=sy;j<=ey;j++) if(!a[x][j]) err();
    if(sx==ex||sy==ey) err();
    if(sx==x||ex==x||sy==y||ey==y) err();
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(i==x&&sy<=j&&j<=ey) continue;
            if(j==y&&sx<=i&&i<=ex) continue;
            if(a[i][j]) err();
        }
    }
    cout<<"YES";
    return 0;
}