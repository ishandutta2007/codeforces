
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
void solve(int T){
    int n;
    scanf("%d",&n);
    int d[105];
    d[0]=0;
    int a[105];
    a[0]=0;
    int ok=1;
    for(int i = 1;i<=n;i++){
        scanf("%d",&d[i]);
        a[i]=a[i-1]+d[i];
        if(a[i-1]-d[i]>=0&&i!=1&&d[i]!=0)ok=0;
    }
    if(ok){
        for(int i = 1;i<=n;i++)printf("%d ",a[i]);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
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