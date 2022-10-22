#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n,t;
long long a[200005];
struct Node
{
    long long val;
    long long cnt;
};
bool operator < (Node x,Node y)
{
    return x.val > y.val;
}
set<Node> S;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        S.clear();
        S.insert((Node){sum,1});
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            while(S.begin()->val > a[i])
            {
                long long tmpval=S.begin()->val,tmpcnt=S.begin()->cnt;
                S.erase(S.begin());
                auto It1 = S.find((Node){tmpval/2,0});
                if(It1 == S.end()) S.insert((Node){tmpval/2,tmpcnt});
                else 
                {
                    long long tmp1=It1->cnt;
                    S.erase(It1);
                    S.insert((Node){tmpval/2,tmpcnt+tmp1});
                }
                auto It2 = S.find((Node){(tmpval+1)/2,0});
                if(It2 == S.end()) S.insert((Node){(tmpval+1)/2,tmpcnt});
                else 
                {
                    long long tmp2=It2->cnt;
                    S.erase(It2);
                    S.insert((Node){(tmpval+1)/2,tmpcnt+tmp2});
                }
            }
            if(S.begin()->val < a[i]) 
            {
                flag=false;
                break;
            }
            long long tmpval=S.begin()->val,tmpcnt=S.begin()->cnt;
            S.erase(S.begin());
            if(tmpcnt!=1) S.insert((Node){tmpval,tmpcnt-1});
        }
        printf(flag ? "YES\n" : "NO\n"); 
    }
}