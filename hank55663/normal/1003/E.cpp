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
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
int main(){
    int n,d,k;
    scanf("%d %d %d",&n,&d,&k);
    if(n<=d){
        printf("NO\n");
    }
    else if(k==1){
        if(n==2&&d==1){
            printf("YES\n1 2\n");
        }
        else
        printf("NO\n");
    }
    else{
        vector<pii> v;
        for(int i=1;i<=d;i++){
            v.pb(mp(i,i+1));
        }
        int now=d+2;
        queue<pair<pii,int> > q;
        for(int i=2;i<=d;i++){
            q.push(mp(mp(i,min(i-1,d+1-i)),k-2));
        }
        while(now!=n+1){
            if(q.empty()){
                printf("NO\n");
                return 0;
            }
            pair<pii,int> p=q.front();
            q.pop();
            if(p.x.y==0)
            continue;
            while(p.y--){
                v.pb(mp(p.x.x,now));
                q.push(mp(mp(now,p.x.y-1),k-1));
                now++;
                if(now==n+1)
                break;
            }
        }
        printf("YES\n");
        for(auto it:v)
        printf("%d %d\n",it.x,it.y);
    }
    return 0;
}