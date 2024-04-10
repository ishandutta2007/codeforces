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
int a[500005];
int cnt[500005];
int main(){
    int m,k,n,s;
    scanf("%d %d %d %d",&m,&k,&n,&s);
    for(int i=1;i<=m;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=s;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    int tot=0;
    int l[500005];
    queue<int> q;
    for(int i=m;i>=1;i--){
        q.push(a[i]);
        cnt[a[i]]--;
        if(cnt[a[i]]>=0)tot++;
        while(tot==s){
            int x=q.front();
            q.pop();
            cnt[x]++;
            if(cnt[x]>0)
            tot--;
        }
        l[i]=i+q.size();
    }
    while(!q.empty()){
        cnt[q.front()]++;
        q.pop();
    }
    int less=m-k*n;
    for(int i=1;i<=m;i++){
        if(l[i]==m+1)
        break;
        int sub=(i-1)%k+max(l[i]-i+1-k,0);
        if(sub<=less){
            printf("%d\n",sub);
            for(int j=0;j<(i-1)%k;j++)
            printf("%d ",j+1);
            sub-=(i-1)%k;
            for(int j=i;j<=l[i];j++){
                if(sub==0)
                break;
                if(cnt[a[j]]){
                    cnt[a[j]]--;
                }
                else{
                    sub--;
                    printf("%d ",j);
                }

            }
            return 0;
        }
    }
    printf("-1\n");
}