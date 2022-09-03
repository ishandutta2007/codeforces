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
    int k;
    scanf("%d",&k);
    int ans[2005];
    ans[0]=1;
    ans[1]=-1000000;
    ans[2]=-1000000;
    for(int i=3;i<1200;i++){
        if(i&1)
            ans[i]=1;
        else
            ans[i]=-2;
    }
    ans[1199]=1300;
    int now_ans=(-598+1300)*1197;
    int len=1197;
    int Max=1;
    while(now_ans<k){
        ans[1199]++;
        Max=max(Max,ans[1199]);
        now_ans+=len;
    }
    ans[0]=now_ans-k;
    while(ans[0]<Max){
        ans[0]+=len;
        ans[1199]++;
        now_ans+=len;
        Max=max(Max,ans[1199]);
    }
    printf("1200\n");
    for(int i=0;i<1200;i++)
    printf("%d ",ans[i]);
}
/*

i f f x f l b
*/