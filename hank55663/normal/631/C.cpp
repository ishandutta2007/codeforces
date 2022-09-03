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
int mod=1e9+7;
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    vector<pii> stk;
    for(int i = 0;i<m;i++){
        int t,r;
        scanf("%d %d",&t,&r);
        while(stk.size()&&stk.back().y<=r){
            stk.pop_back();
        }
        if(stk.empty()||stk.back().x!=t)
        stk.pb(mp(t,r));
    }
    sort(a,a+stk[0].y);
    stk.pb(mp(0,0));
    vector<int> tmp;
    int l=0,r=stk[0].y-1;
    for(int i = 0;i<stk.size()-1;i++){
        if(stk[i].x==1){
            for(int j = 0;j<stk[i].y-stk[i+1].y;j++){
                tmp.pb(a[r]);
                r--;
            }
        }
        else{
            for(int j = 0;j<stk[i].y-stk[i+1].y;j++){
                tmp.pb(a[l]);
                l++;
            }
        }
    }
    reverse(tmp.begin(),tmp.end());
    for(auto it:tmp)printf("%d ",it);
    for(int i = stk[0].y;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}