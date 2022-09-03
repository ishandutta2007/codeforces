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
int a[505][505];
int c[505];
vector<pii> edge;
int num;
int go(vector<int> v){
    if(v.size()==1){
        c[v[0]]=a[v[0]][v[0]];
        return v[0];
    }
    int Max=0;
    for(auto it:v){
        for(auto it2:v){
            Max=max(Max,a[it][it2]);
        }
    }
    int val=num++;
    c[val]=Max;
    vector<vector<int> > tmp;
    for(auto it:v){
        int ok=0;
        for(auto &it2:tmp){
            if(a[it2[0]][it]!=Max){
                it2.pb(it);
                ok=1;
                break;
            }
        }
        if(!ok){
            tmp.pb(vector<int>{it});
        }
    }
    for(auto &it:tmp){
        int x=go(it);
        edge.pb(mp(x,val));
    }
    return val;
}
void solve(){
    int n;
    scanf("%d",&n);
    num=n+1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    vector<int> v;
    for(int i = 1;i<=n;i++){
        v.pb(i);
    }
    int x=go(v);
    printf("%d\n",num-1);
    for(int i = 1;i<num;i++)printf("%d ",c[i]);
    printf("\n");
    printf("%d\n",x);
    //printf("%d")
    for(auto it:edge){
        printf("%d %d\n",it.x,it.y);
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/