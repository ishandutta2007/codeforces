
#pragma GCC optimize("Ofast") 
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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int dep[30];
int main(){
    LL n,s;
    scanf("%lld %lld",&n,&s);
    if(s<n+n-1){
        printf("NO\n");
    }
    else if(s>n*(n+1)/2){
        printf("NO\n");
    }
    else if(s==n*(n+1)/2){
        printf("YES\n");
        for(int i=1;i<=n-1;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
    else{
        printf("YES\n");
        for(int i=2;;i++){
            MEM(dep);
            int tot=1;
            LL sum=1;
            dep[1]=1;
            for(int j=2;tot<n;j++){
                dep[j]=min((LL)dep[j-1]*i,n-tot);
                sum+=dep[j]*j;
                tot+=dep[j];
            }
            if(sum<=s){
                int ans[100005];
                MEM(ans);
                ans[1]=1;
                tot=1;
                sum=1;
                int j;
                for(j=2;tot<n;j++){
                    ans[j]=min((LL)ans[j-1]*i,n-tot);
                    sum+=(LL)ans[j]*j;
                    tot+=ans[j];
                }

                int now=j-1;
                while(sum<s){
                    while(ans[now]==1)now--;
                    if(sum+j-now<=s){
                        ans[j]++;
                        ans[now]--;
                        sum+=j-now;
                    }
                    else{
                        int need=s-sum;
                        ans[now+need]++;
                        ans[now]--;
                        sum+=need;
                    }
                    j++;
                }
                vector<vector<int> > v(j);
                now=1;
                for(int k=1;k<j;k++){
                    while(ans[k]--){
                        if(now!=1){
                            printf("%d ",v[k-1][v[k].size()/i]);
                        }
                        v[k].pb(now);
                        now++;
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
}