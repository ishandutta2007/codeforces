#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[5][55];
    for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    vector<pair<int,pii> > ans;
    int ok[105];
    MEM(ok);
    for(int i=0;i<20000;i++){
        int ook=1;
        for(int i=1;i<=k;i++)
        if(!ok[i])ook=0;
        if(ook)
        break;
        for(int i=1;i<=n;i++)
        if(a[1][i]==a[2][i]&&a[1][i]!=0){
            ans.pb(mp(a[1][i],mp(1,i)));
            a[2][i]=0;
            ok[a[1][i]]=1;
        }
        for(int i=1;i<=n;i++)
        if(a[3][i]==a[4][i]&&a[4][i]!=0){
            ans.pb(mp(a[3][i],mp(4,i)));
            a[3][i]=0;
            ok[a[4][i]]=1;
        }
        int move=1;
        if(a[3][1]==0&&a[2][1]){
            ans.pb(mp(a[2][1],mp(3,1)));
            a[3][1]=a[2][1];
            a[2][1]=0;
            move=2;
        }
        for(int i=2;i<=n;i++){
            if(a[2][i-1]==0&&a[2][i]){
                ans.pb(mp(a[2][i],mp(2,i-1)));
                a[2][i-1]=a[2][i];
                a[2][i]=0;
            }
        }
        if(n!=1&&a[2][n]==0&&a[3][n]){
            ans.pb(mp(a[3][n],mp(2,n)));
            a[2][n]=a[3][n];
            a[3][n]=0;
        }
        for(int i=n-1;i>=move;i--){
            if(a[3][i+1]==0&&a[3][i]){
                ans.pb(mp(a[3][i],mp(3,i+1)));
                a[3][i+1]=a[3][i];
                a[3][i]=0;
            }
        }
    }
    if(ans.size()>20000){
        printf("-1n");
        return 0;
    }
    for(int i=1;i<=k;i++){
        if(!ok[i]){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d %d %d\n",it.x,it.y.x,it.y.y);
    return 0;
}