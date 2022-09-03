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
#define MAXN 605
int main(){
    int n;
    char c[200005];
    scanf("%d %s",&n,c);
    int cnt=0;
    char color[10]="RGB";
    int num[128];
    num['R']=0;
    num['G']=1;
    num['B']=2;
    for(int i=1;c[i]!=0;i++){
        if(c[i]==c[i-1]){
            int vis[3];
            MEM(vis);
            vis[num[c[i]]]=1;
            if(i!=n-1)
            vis[num[c[i+1]]]=1;
            for(int j=0;j<3;j++){
                if(!vis[j])
                    c[i]=color[j];
            }
            cnt++;
        }
    }
    printf("%d\n",cnt);
    printf("%s\n",c);
}