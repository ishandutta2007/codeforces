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
#define MXN 100005
int cnt[300005];
int tot2[300005];
bool solve(){
    int n;
    scanf("%d",&n);
    fill(cnt,cnt+n+1,0);
    fill(tot2,tot2+n+1,0);
    int a[300005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int tot=0;

    for(int i = 1;i<n;i++){
        if(a[i]==a[i-1]){
            tot++;
            tot2[a[i]]++;
        }
    }
    int Max=0,Maxi;
    for(int i = 1;i<=n;i++){
        if(tot2[i]>Max){
            Max=tot2[i];
            Maxi=i;
        }
    }
    int less=tot-Max;
    if(a[0]!=Maxi)Max--;
    if(a[n-1]!=Maxi)Max--;

    Max-=less;
    for(int i = 1;i<=n;i++){
        if(cnt[i]*2-1>n){
            printf("-1\n");
            return true;
        }
    }
    printf("%d\n",tot+max(Max,0));
    return true;
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}
/*

2 3
1 3
4 2
2 5
3 5
1 2
5 4
*/