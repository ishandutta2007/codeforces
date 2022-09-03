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
#define hash Hash
vector<int> v[5005];
int push[5005];
int ok[5005];
int main(){
    int n,m,s;
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
    }
    queue<int> q;
    q.push(s);
    ok[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(!ok[it]){
                ok[it]=1;
                q.push(it);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!ok[i]){
            ans++;
            q.push(i);
            ok[i]=1;
            int temp[5005];
            MEM(temp);
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto it:v[x]){
                    if(!temp[it]){
                        temp[it]=1;
                        ok[it]=1;
                        q.push(it);
                    }
                    if(push[it]){
                        push[it]=0;
                        ans--;
                    }
                }
            }
            push[i]=1;
        }
    }
    printf("%d\n",ans);
}