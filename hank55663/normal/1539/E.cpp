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
static const double INF = 2147483647;
int dpl[100005],dpr[100005];
void solve(){
    MEMS(dpl);
    MEMS(dpr);
    int n,m;
    scanf("%d %d",&n,&m);
    set<pii> l,r;
    l.insert(mp(0,0));
    r.insert(mp(0,0));
    for(int i = 1;i<=n;i++){
        int k;
        int la,lb,ra,rb;
        scanf("%d %d %d %d %d",&k,&la,&lb,&ra,&rb);
        int okl=0,okr=0;
        if(k>=la&&k<=lb)okl=1;
        if(k>=ra&&k<=rb)okr=1;
        while(l.size()&&l.begin()->x<la){
            l.erase(l.begin());
        }
        while(l.size()&&l.rbegin()->x>lb){
            l.erase(*l.rbegin());
        }
        while(r.size()&&r.begin()->x<ra){
            r.erase(r.begin());
        }
        while(r.size()&&r.rbegin()->x>rb){
            r.erase(*r.rbegin());
        }
        int ookl=0,ookr=0;
        if(okl&&r.size()){
            dpl[i]=r.begin()->y;
           // l.insert(mp(k,i));
            ookl=1;
        }
        if(okr&&l.size()){
            dpr[i]=l.begin()->y;
           // r.insert(mp(k,i));
            ookr=1;
        }
        if(!ookr)l.clear();
        if(!ookl)r.clear();
        if(ookl)l.insert(mp(k,i));
        if(ookr)r.insert(mp(k,i));
        if(!ookl&&!ookr){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    vector<int> v;
    if(dpl[n]!=-1){
        int l=1;
        int now=n;
        while(now){
            if(l){
                int x=dpl[now];
                for(int i = now;i>x;i--)v.pb(0);
                now=x;
            }
            else{
                int x=dpr[now];
                for(int i = now;i>x;i--)v.pb(1);
                now=x;
            }
            l^=1;
        }
    }
    else{
        int l=0;
        int now=n;
         while(now){
            if(l){
                int x=dpl[now];
                for(int i = now;i>x;i--)v.pb(0);
                now=x;
            }
            else{
                int x=dpr[now];
                for(int i = now;i>x;i--)v.pb(1);
                now=x;
            }
            l^=1;
        }
    }
    reverse(v.begin(),v.end());
    for(auto it:v)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6 7
5 5 5 5 5 6 6 6 6 6 7 7 7

3 3 4 4 5 5 6 6 7 7 8
5 5 5 6 6 6 7 7 7 8 8 

3 3 4 4 5 5 6
5 5 5 5 5 5 5 

1 1 6
0 -3 -3

0 0 5
1 -2 -2
-2 -2 3
3 0 0
1 1
1 2 1
1 3 2 3 1
1 4 3 5 2 5 3 4 1
1 5 4 7 3 8 5 7 2 7 5 8 3 7 4 5 1
*/