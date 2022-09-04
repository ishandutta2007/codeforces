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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,k;
        scanf("%lld %lld",&n,&k);
        LL tot=0;
        for(LL i=0,now=1;i<n&&tot<k;i++,now*=4){
            tot+=now;
        }
        if(tot<k){
            printf("NO\n");
        }
        else{
            k--;
            tot=0;
            for(LL i=0,now=1;i<n-1&&tot<k;i++,now*=4){
                tot+=now;
            }
            if(tot>=k){
                printf("YES %lld\n",n-1);
            }
            else{
                LL cnt[64];
                cnt[0]=0;
                for(int i=1;i<64;i++)
                cnt[i]=cnt[i-1]*4+1;
                LL last=1;
                tot=cnt[n-1];
                for(int i=n-2;i>=0;i--){
                    k-=last+2;
                    if(k<0){
                        printf("NO\n");
                        break;
                    }
                    last=(last+1)*2+1;
                    LL ori=tot;
                    tot+=cnt[i]*last;
                    LL add=cnt[i]*last;
                    if(tot>=k||add%last!=0||ori>tot){
                        printf("YES %d\n",i);
                        break;
                    }
                }
            }
        }
    }
}
/*
1000000000 1000000000
1 1 1000000000 1000000000
1 1 1000000000 1000000000

*/