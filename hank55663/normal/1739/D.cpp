
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
vector<int> v[200005];
int cnt=0;
int dfs(int x,int f,int d){
    int dd=0;
    for(auto it:v[x]){
        if(it!=f){
            dd=max(dd,dfs(it,x,d));
        }
    }
    dd++;
    if(dd>=d&&f!=1&&x!=1)cnt++,dd=0;
   // printf("%d %d\n",x,dd);
    return dd;
}
void solve(int T){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 2;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        dfs(1,0,mid);
      //  printf("? %d %d\n",mid,cnt);
        if(cnt>k)Min=mid;
        else Max=mid;
        cnt=0;
    }
    printf("%d\n",Max);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/