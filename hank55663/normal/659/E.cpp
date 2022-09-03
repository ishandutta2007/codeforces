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
int ok[100005];
int Size[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        f[i]=i;
        Size[i]=1;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int a=Find(x),b=Find(y);
        if(a==b){
            //printf("%d %d %d %d\n",x,y,a,b);
            ok[a]=1;
        }
        else{
            f[b]=a;
            ok[a]|=ok[b];
            Size[a]+=Size[b];
        }
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
      //  printf("%d %d %d\n",f[i],ok[i],Size[i]);
        if(f[i]==i&&!ok[i])ans++;
    }
    printf("%d\n",ans);
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}