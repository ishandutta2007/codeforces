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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)v[i].clear();
    int a[200005];
    map<int,int> m;

    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
       // if(s.find(a[i])==s.end()){
            v[m[a[i]]].pb(mp(a[i],i));
            m[a[i]]++;
          //  s.insert(a[i]);
        //}
    }
    for(int i = 0;i<n;i++){
        if(v[i].size()){
            sort(v[i].begin(),v[i].end());
            v[i].pb(v[i][0]);
            for(int j = 1;j<v[i].size();j++){
                a[v[i][j-1].y]=v[i][j].x;
            }
        }
    }
    /*v.pb(v[0]);
    for(int j = 1;j<v.size();j++){
        a[v[j-1].y]=v[j].x;
    }*/
    for(int i = 0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/