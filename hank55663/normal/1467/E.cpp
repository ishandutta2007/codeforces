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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
vector<int> v[200005];
int a[200005];
map<int,int> cnt;
int val[200005];
int in[200005];
int out[200005];
int t;
map<int,int> dfs(int x,int f){
    map<int,int> res;
    in[x]=++t;
    for(auto it:v[x]){
        if(it!=f){
            auto ss=dfs(it,x);
            if(ss.find(a[x])!=ss.end()){
                val[1]++;
                val[in[it]]--;
                val[out[it]+1]++;
              //  printf("%d %d\n",1,in[it]);
               // printf("%d\n",out[it]+1);
            }
            if(ss.size()>res.size())swap(ss,res);
            for(auto it2:ss){
                res[it2.x]+=it2.y;
            }
        }
    }
    out[x]=t;
    res[a[x]]++;
    if(res[a[x]]!=cnt[a[x]]){
        val[in[x]]++,val[out[x]+1]--;
     //   printf("%d %d\n",in[x],out[x]+1);
    }
    return res;
}
bool solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    int sum=0;
    int ans=0;
    for(int i = 1;i<=n;i++){
        sum+=val[i];
        if(!sum)ans++;
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;//00000;
 //   scanf("%d",&t);
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