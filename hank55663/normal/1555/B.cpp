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
    int W,H;
    scanf("%d %d",&W,&H);
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int w,h;
    scanf("%d %d",&w,&h);
    int w2=x2-x1,h2=y2-y1;
    int ans=1e9;
    if(w2+w<=W&&max(h,h2)<=H){
        ans=min(ans,max(0,w-x1));
        ans=min(ans,max(0,x2-(W-w)));
    }
    if(max(w2,w)<=W&&h+h2<=H){
        ans=min(ans,max(0,h-y1));
        ans=min(ans,max(0,y2-(H-h)));
    }
    if(ans==1e9)printf("-1\n");
    else printf("%d\n",ans);
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
3 1 4 2
3 3 4 4
*/