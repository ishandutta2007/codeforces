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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int l[100005];
    l[0]=0;
    LL tot=0;
    for(int i = 1;i<=m;i++){
        scanf("%d",&l[i]);
        if(l[i]+i-1>n){
            printf("-1\n");
            return 0;
        }
        tot+=l[i];
        
    }
    if(tot<n){
        printf("-1\n");
        return 0;
    }
    int ans[100005];
    ans[m+1]=n+1;
    for(int i = m;i>=1;i--){
        ans[i]=max(ans[i+1]-l[i],i);
        //if(ans[i])
    }
    for(int i = 1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
/*

*/