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
vector<int> v[200005];
int degree[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear(),degree[i]=0;
    int a[200005];
    int b[200005];
    map<int,int> m;
    for(int i = 0;i<n;i++)scanf("%d",&a[i]),m[a[i]]++;
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    int Max=0,Maxi;
    for(auto it:m){
        if(it.y>Max){
            Max=it.y;
            Maxi=it.x;
        }
    }
    for(int i = 0;i<n;i++){
        if(a[i]!=Maxi&&b[i]!=Maxi)
        v[a[i]].pb(b[i]),degree[b[i]]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(i!=Maxi&&degree[i]==0)q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cnt++;
        for(auto it:v[x]){
            if(--degree[it]==0)q.push(it);
        }
    }
    if(cnt==n-1)printf("AC\n");
    else printf("WA\n");
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