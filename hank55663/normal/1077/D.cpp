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
#define hash Hash
#define LL long long
int main(){
    int n,k;
    map<int,int> cnt;
    scanf("%d %d",&n,&k);
    //fill(cnt,cnt+200005,0);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    int Max=2e5+1,Min=1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int sum=0;
        for(auto it:cnt){
            sum+=it.y/mid;
        }
        if(sum>=k){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    for(auto it:cnt){
        int tot=it.y/Min ;
        while(tot--&&k--){
            printf("%d ",it.x);
        }
        if(k<=0)
        break;
    }
}