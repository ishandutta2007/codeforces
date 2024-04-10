#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    int L,R;
    long long val;
};
vector<node> Now,Nxt;
long long a[200005],b[200005];
long long gcd(long long x,long long y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d",&n);
        Now.clear();
        scanf("%lld",&b[1]);
        for(int i=1;i<=n-1;i++)
        {
            scanf("%lld",&b[i+1]);
            a[i]=abs(b[i+1]-b[i]);
            Nxt.clear();
            Now.push_back((node){i,i,a[i]});
            for(auto &p : Now)
            {
                long long tmp=gcd(p.val,a[i]);
                if(tmp!=1) ans=max(ans,i-p.L+1);
                if(!Nxt.empty() && Nxt.back().val==tmp)
                {
                    Nxt[Nxt.size()-1].R=p.R;
                }
                else
                {
                    Nxt.push_back((node){p.L,p.R,tmp});
                }
            }
            Now=Nxt;
        }
        if(n==1) printf("1\n");
        else printf("%d\n",ans+1);
    }
}