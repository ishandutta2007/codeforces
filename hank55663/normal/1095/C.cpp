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
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k>n)
    printf("NO\n");
    else{
        priority_queue<int> pq;
        int now=1;
        int kk=n;
        while(kk){
            if(kk&1)
            pq.push(now);
            kk>>=1;
            now<<=1;
        }
        if(pq.size()>k){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            while(pq.size()!=k){
                int x=pq.top();
                pq.pop();
                pq.push(x/2);
                pq.push(x/2);
            }
            while(!pq.empty()){
                printf("%d ",pq.top());
                pq.pop();
            }
            printf("\n");
        }
    }
    return 0;
}