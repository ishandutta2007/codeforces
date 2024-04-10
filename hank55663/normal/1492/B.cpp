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
    int n;
    scanf("%d",&n);
    int p[100005];
    for(int i =  0;i<n;i++)scanf("%d",&p[i]);
    vector<vector<int> > v;
    int vis[100005];
    int now=n;
    fill(vis,vis+n+1,0);
    vector<int> tmp;
    tmp.pb(p[0]);
    for(int i = 1;i<n;i++){
        if(p[i]>tmp[0]){
            v.pb(tmp);
            tmp.clear();
        }
        tmp.pb(p[i]);
    }
    v.pb(tmp);
    reverse(v.begin(),v.end());
    for(auto it:v){
        for(auto it2:it)printf("%d ",it2);
    }
    printf("\n");
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