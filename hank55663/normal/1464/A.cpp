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
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)f[i]=i;
    //pii p[100005];
    int cnt=0;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x!=y){
            cnt++;
            int a=Find(x),b=Find(y);
            if(a==b){
                cnt++;
            }
            else{
                f[a]=b;
            }
        }
    }
    printf("%d\n",cnt);
    return true;
}
int main(){
    int t=1;//000000;//000000;
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