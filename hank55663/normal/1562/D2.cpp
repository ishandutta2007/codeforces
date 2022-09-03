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
#define MXN 3000000

vector<int> up[600005],down[600005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[300005];
    scanf("%s",c+1);
    for(int i = -n;i<=n;i++)up[i+300000].clear(),down[i+300000].clear();
    int pre[300005];
    pre[0]=0;
    for(int i = 1;c[i]!=0;i++){
        int add=1;
        if(c[i]=='+'){
            add=1;
        }
        else add=-1;
        if(i%2==0)add*=-1;
        pre[i]=pre[i-1]+add;
       // printf("%d ",)
    }
    for(int i = 0;c[i+1]!=0;i++){
        if(pre[i+1]==pre[i]+1)up[pre[i]+300000].pb(i);
        else down[pre[i]+300000].pb(i);
    }
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);

        if(pre[r]-pre[l-1]==0)printf("0\n");
        else{
            if((r-l+1)%2){
                int val=pre[r]-pre[l-1];
                printf("1\n");
                if(val>0){
                    int t=pre[l-1]+val/2+1;
                    if(pre[r-1]==pre[l-1])printf("%d\n",r);
                    else
                    printf("%d\n",*lower_bound(up[t+300000].begin(),up[t+300000].end(),l));
                }
                else{
                    int t=pre[l-1]+val/2-1;
                     if(pre[r-1]==pre[l-1])printf("%d\n",r);
                    else
                    printf("%d\n",*lower_bound(down[t+300000].begin(),down[t+300000].end(),l));
                }
            }
            else{
                printf("2\n");
                printf("%d ",l);
                l++;
                 int val=pre[r]-pre[l-1];
                //printf("1\n");
                if(val>0){
                    int t=pre[l-1]+val/2+1;
                     if(pre[r-1]==pre[l-1])printf("%d\n",r);
                    else
                    printf("%d\n",*lower_bound(up[t+300000].begin(),up[t+300000].end(),l));
                }
                else{
                    int t=pre[l-1]+val/2-1;
                     if(pre[r-1]==pre[l-1])printf("%d\n",r);
                    else
                    printf("%d\n",*lower_bound(down[t+300000].begin(),down[t+300000].end(),l));
                }

            }
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
100
5 6
9 10 7 5
4 4 4 9
1 2
4 5
3 5
2 3
1 4
1 5

110111
*/