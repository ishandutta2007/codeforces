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
void solve(){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    int ans=0,sum=0;
    sort(a,a+n);
    reverse(a,a+n);
    for(int i = 0;i<n;i++){
        int x=d/a[i]+1;
        if(sum+x<=n){
            ans++;
            sum+=x;
        }
        else{
            break;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
*/