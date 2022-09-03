#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int f[200005];
int cnt[200005][26];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        char c[200005];
        scanf("%s",c + 1);
        for(int i = 1;i<=n;i++){
            f[i]=i;
            MEM(cnt[i]);
        }
        for(int i = 1;i<=n;i++){
            int a=Find(i),b=Find(n+1-i);
            f[a]=b;
        }
        for(int i = 1;i<=n-k;i++){
            int a=Find(i),b=Find(k+i);
            f[a]=b;
        }
        for(int i = 1;i<=n;i++){
            cnt[Find(i)][c[i]-'a']++;
        }
        int ans=0;
        for(int i = 1;i<=n;i++){
            if(Find(i)==i){
                int sum=0,Max=0;
                for(int j = 0;j<26;j++){
                    sum+=cnt[i][j];
                    Max=max(Max,cnt[i][j]);
                }
                ans+=sum-Max;
            }
        }
        printf("%d\n",ans);
    }
}