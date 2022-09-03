#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        char c[200005];
        scanf("%s",c);
        int cnt[200005];
        fill(cnt,cnt+n,0);
        for(int i = 0;i<m;i++){
            int x;
            scanf("%d",&x);
            x--;
            cnt[x]++;
        }
        cnt[n-1]++;
        for(int i = n-2;i>=0;i--)cnt[i]+=cnt[i+1];
        int ans[26];
        MEM(ans);
        for(int i = 0;c[i]!=0;i++){
            ans[c[i]-'a']+=cnt[i];
        }
        for(int i = 0;i<26;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
}