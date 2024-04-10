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
bool solve(){
    int n;
    scanf("%d",&n);
    int need=-1e9;
    int last=-1;
    int now=0,Next=0;
    int ans=0;
    for(int i = 0;i<n;i++){
        int t,x;
        scanf("%d %d",&t,&x);
        int l,r;
        if(Next>now){
            l=now,r=min(Next,l+t-last);
        }
        else{
            l=max(Next,now-t+last),r=now;
        }
        if(need>=l&&need<=r){
            ans++;
        }
       // printf("%d %d %d\n",l,need,r);
        need=x;
        if(Next>now)now=r;
        else now=l;
        if(now==Next){
            Next=x;
        }
        last=t;
        
    }
    int l,r;
        if(Next>now){
            l=now,r=Next;
        }
        else{
            l=Next,r=now;
        }
        if(need>=l&&need<=r){
            ans++;
        }
      //  printf("%d %d %d\n",l,need,r);
    printf("%d\n",ans);
    return true;
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}