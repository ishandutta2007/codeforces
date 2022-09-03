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
const int mod=998244353;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[10004];
    MEM(a);
    int an[10004],o[10004];
    for(int i=0;i<n-1;i++){
        printf("or %d %d\n",i+1,i+2);
        fflush(stdout);
        scanf("%d",&o[i]);
        printf("and %d %d\n",i+1,i+2);
        fflush(stdout);
        scanf("%d",&an[i]);
    }
    int tan,to;
        printf("or %d %d\n",1,3);
        fflush(stdout);
        scanf("%d",&to);
        printf("and %d %d\n",1,3);
        fflush(stdout);
        scanf("%d",&tan);
    for(int i = 29;i>=0;i--){
        int cnt[10004];
        fill(cnt,cnt+10004,0);
        int ans[10004];
        fill(ans,ans+10004,-1);
        for(int j = 0;j<n-1;j++){
            if(o[j]&(1<<i))cnt[j]++;
            if(an[j]&(1<<i))cnt[j]++;
        }
        for(int j = 0;j<n-1;j++){
            if(cnt[j]==0)ans[j]=ans[j+1]=0;
            else if(cnt[j]==2)ans[j]=ans[j+1]=1;
            else{
                if(j!=0&&ans[j]!=-1)ans[j+1]=1-ans[j];
            }
        }
        for(int j = n-2;j>=0;j--){
            if(cnt[j]==1){
                if(ans[j]==-1&&ans[j+1]!=-1)ans[j]=1-ans[j+1];
            }
        }
        if(ans[0]==-1){
            if(tan&(1<<i)){   
                for(int j = 0;j<n;j++){
                    ans[j]=1-j%2;
                }

            }
            else if(!(to&(1<<i))){
                for(int j=0;j<n;j++){
                    ans[j]=j%2;
                }
            }
        }
        for(int j = 0;j<n;j++){
            a[j]|=(ans[j])<<i;
        }
    }
    //for(int j = 0;j<n;j++)printf("%d ",a[j]);
    //printf("\n");
    sort(a,a+n);
    printf("finish %d\n",a[k-1]);
    fflush(stdout);

}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
*/