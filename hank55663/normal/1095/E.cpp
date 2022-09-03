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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
int cnt[1000005];
int cnt2[1000005];
int main(){
    int n;
    scanf("%d",&n);
    char c[1000005];
    scanf("%s",c+1);
    if(n&1)
    {
        printf("0\n");
        return 0;
    }

    MEM(cnt);
    for(int i=1;c[i]!=0;i++){
        if(c[i]=='('){
            cnt[i]=cnt[i-1]+1;
        }
        else{
            if(cnt[i-1])
            cnt[i]=cnt[i-1]-1;
            else{
                cnt[i]=-1e9;
            }
        }
       // printf("%d",cnt[i]);
    }
    //printf("\n");
    int ans=0;
    for(int i=n;i>0;i--){
        if(c[i]==')'){
            cnt2[i]=cnt2[i+1]+1;
            if(cnt2[i]-2==cnt[i-1]&&cnt[i-1]>=0&&cnt2[i]>=0)ans++;
        }
        else{
            if(cnt2[i+1]){
                cnt2[i]=cnt2[i+1]-1;
                if(cnt2[i]+2==cnt[i-1]&&cnt[i-1]>=0&&cnt2[i]>=0)ans++;
            }
            else{
                if(cnt2[i+1]==0){
                    if(cnt[i-1]==1){
                        ans++;
                    }
                }
                cnt2[i]=-1e9;
            }
        }
      //  printf("%d ",cnt2[i]);
    }
   // printf("\n");
    printf("%d\n",ans);
    return 0;
}