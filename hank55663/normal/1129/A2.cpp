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
vector<int> v[5005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(b<a)
        b+=n;
        v[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=n;j++){
            if(!v[j].empty())
            ans=max(ans,(int)(v[j].size()-1)*n+(j-i+n)%n+v[j].back()-j);
        }
        printf("%d ",ans);
    }
}
/*
10101
0101
0 1 0 1
01 0 1
0 10 1
0 1 01
01 01
010 1
0 101
0101
10101
1 0 1 0 1
10 1 0 1
1 01 0 1
1 0 10 1
1 0 1 01
10 10 1
10 1 01
1 01 01
i f f x f l b
*/