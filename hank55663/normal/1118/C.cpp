#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int main(){
    int n;
    scanf("%d",&n);
    int cnt[1005];
    MEM(cnt);
    for(int i=0;i<n*n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    vector<int> cnt4,cnt2,cnt1;
    for(int i=1;i<=1000;i++){
        while(cnt[i]>=4){
            cnt4.pb(i);
            cnt[i]-=4;
        }
        while(cnt[i]>=2){
            cnt2.pb(i);
            cnt[i]-=2;
        }
        while(cnt[i]>=1){
            cnt1.pb(i);
            cnt[i]--;
        }
    }
    if(n%2==0){
        if(cnt2.size()||cnt1.size()){
            printf("No\n");
        }
        else{
            printf("YES\n");
            int ans[20][20];
            int index=0;
            for(int i=0;i<n/2;i++)
                for(int j=0;j<n/2;j++)
                    ans[i][j]=cnt4[index++];
            index=0;
            for(int i=0;i<n/2;i++)
                for(int j=n-1;j>=n/2;j--)
                    ans[i][j]=cnt4[index++];
            index=0;
            for(int i=n-1;i>=n/2;i--)
                for(int j=0;j<n/2;j++)
                    ans[i][j]=cnt4[index++];
            index=0;
            for(int i=n-1;i>=n/2;i--)
                for(int j=n-1;j>=n/2;j--)
                    ans[i][j]=cnt4[index++];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    printf("%d ",ans[i][j]);
                printf("\n");
            }
        }
    }
    else{
        if(cnt1.size()!=1||(cnt2.size()>n-1)){
            printf("No\n");
        }
        else{
            printf("YES\n");
            int ans[20][20];
            int index=0;
            for(int i=0;i<n/2;i++)
                for(int j=0;j<n/2;j++)
                    ans[i][j]=cnt4[index++];
            index=0;
            for(int i=0;i<n/2;i++)
                for(int j=n-1;j>n/2;j--)
                    ans[i][j]=cnt4[index++];
            index=0;
            for(int i=n-1;i>n/2;i--)
                for(int j=0;j<n/2;j++)
                    ans[i][j]=cnt4[index++];
            index=0;
            for(int i=n-1;i>n/2;i--)
                for(int j=n-1;j>n/2;j--)
                    ans[i][j]=cnt4[index++];
            while(index!=cnt4.size()){
                cnt2.pb(cnt4[index]);
                cnt2.pb(cnt4[index]);
                index++;
            }
            ans[n/2][n/2]=cnt1[0];
            index=0;
            for(int i=0;i<n/2;i++){
                if(i!=n/2){
                    ans[i][n/2]=ans[n-i-1][n/2]=cnt2[index];
                    index++;
                    ans[n/2][i]=ans[n/2][n-i-1]=cnt2[index];
                    index++;
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    printf("%d ",ans[i][j]);
                printf("\n");
            }
        }
    }
}