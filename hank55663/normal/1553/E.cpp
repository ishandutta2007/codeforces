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
vector<int> v[26];
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int p[300005];
    int cnt[300005];
    fill(cnt,cnt+n+1,0);
    for(int i = 0;i<n;i++){
        scanf("%d",&p[i]);
        p[i]--;
        cnt[(i-p[i]+n)%n]++;
    }
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(cnt[i]>n/4){
            int ori[300005];
            for(int j = 0;j<n;j++){
                ori[j]=(j-i+n)%n;
            }
            for(int j = 0;j<n;j++)f[j]=j;
            for(int j=0;j<n;j++){
                int a=Find(ori[j]),b=Find(p[j]);
                f[a]=b;
            }
            int tot=0;
            for(int j = 0;j<n;j++){
                if(f[j]==j)tot++;
            }
            if(n-tot<=m)ans.pb(i);
        }
    }
    printf("%d ",ans.size());
    for(auto it:ans)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/