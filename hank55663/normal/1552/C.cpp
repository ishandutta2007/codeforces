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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    pii p[105];
    int vis[205];
    fill(vis,vis+2*n+1,0);
    int tot=2*n-2*k;
    for(int i =0;i<k;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
        vis[p[i].x]=1;
        vis[p[i].y]=1;
    }
    int ans=0;
    for(int i = 0;i<k;i++){
        int ttot=0;
        for(int j=p[i].x;j!=p[i].y;j=j%(2*n)+1){
            if(!vis[j])ttot++;
        }
        ans+=min(ttot,tot-ttot);
        // printf("%d %d %d\n",ans,tot,ttot);
    }
    //  printf("%d\n",ans);
    ans+=tot/2*(tot/2-1)/2;
     // printf("%d\n",ans);
    for(int i = 0;i<k;i++){
        if(p[i].x>p[i].y)swap(p[i].x,p[i].y);
        for(int j = i+1;j<k;j++){
            int cnt=0;
            if(p[j].x>p[i].x&&p[j].x<p[i].y)cnt++;
            if(p[j].y>p[i].x&&p[j].y<p[i].y)cnt++;
            if(cnt==1)ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
0 1 1 1
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
x^2+y^2=kxy+k;
64+y^2=32y+4;
y^2-32y+60=0;

x^2-k*y*x-k+y*y=0;
a=1;
b=-k*y;
c=y*y-k
x=ky+-sqrt(k*k*y*y+4*k-4*y*y) 
*/