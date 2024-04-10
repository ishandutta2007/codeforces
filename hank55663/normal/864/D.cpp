#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int vis[200005];
    fill(vis,vis+n+1,0);
    int cnt[200005];
    fill(cnt,cnt+n+1,0);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int ans[200005];
    int last[200005];
    fill(ans,ans+n,0);
    set<int> s;
    for(int i = 0;i<n;i++){
        last[a[i]]=i;
        if(cnt[a[i]]==1){
            ans[i]=a[i];
        }
        if(cnt[i+1]==0){
            s.insert(i+1);
        }
    }
    printf("%d\n",s.size());
    for(int i = 0;i<n;i++){
       // printf("%d\n",i);
        if(ans[i]==0){
            if(!vis[a[i]]){
                if(i!=last[a[i]]&&(s.size()&&*s.begin()<a[i])){
                    ans[i]=*s.begin();
                    s.erase(s.begin());
                }
                else{
                    ans[i]=a[i];
                    vis[a[i]]=1;
                }
            }
            else{
                ans[i]=*s.begin();
                s.erase(s.begin());
            }
        }
        printf("%d ",ans[i]);
    }
    printf("\n");
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/