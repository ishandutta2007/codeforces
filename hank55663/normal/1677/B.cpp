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
#define index Index
int ans[1000005];
int sub[1000005];
int val[1000005];
int pre[1000005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[1000005];
    for(int i = 1;i<=n*m;i++){
        char c;
        scanf(" %c",&c);
        a[i]=c-'0';
        if(i<=m){
            ans[i]=1;
        }
        else{
            ans[i]=((i-1)/m)+1;
        }
        pre[i]=pre[i-1]+a[i];
    }
    fill(sub,sub+n*m+5,0);
    fill(val,val+n*m+5,0);
    for(int i = 1;i<=n*m;i++){
        if(pre[i]-pre[max(i-m,0)]==0){
            sub[i]++;
        }   
    }
    for(int i = 0;i<m;i++)ans[i]-=sub[i];
    for(int i = m;i<=n*m;i++){
        sub[i]+=sub[i-m];
        ans[i]-=sub[i];
    }
    int add=0;
    for(int i = 1;i<=n*m;i++){
        if(a[i]){
            if(val[i%m]==0){
                add++;
                val[i%m]=1;
            }
        }
        ans[i]+=add;
        printf("%d ",ans[i]);
    }
    printf("\n");
}  
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}