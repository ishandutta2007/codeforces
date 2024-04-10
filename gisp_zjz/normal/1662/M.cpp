#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int t,n,m,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int mx=0,my=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mx=max(mx,x); my=max(my,y);
        }
        if(mx+my>n) puts("IMPOSSIBLE");
        else
        {
            mx=max(mx,n-my);
            for(int i=0;i<mx;i++) printf("R");
            for(int i=0;i<my;i++) printf("W");
            puts("");
        }
    }
    return 0;
}