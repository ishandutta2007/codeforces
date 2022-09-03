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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[200005];
int ans;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y)cnt[y]++;
        else cnt[x]++;
    }
    for(int i = 1;i<=n;i++){
        if(cnt[i]==0)ans++;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>y){
                swap(x,y);
            }
            if(cnt[x]==0)ans--;
            cnt[x]++;
        }
        else if(op==2){
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>y)swap(x,y);
            cnt[x]--;
            if(cnt[x]==0)ans++;
        }
        else{
            printf("%d\n",ans);
        }
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
*/