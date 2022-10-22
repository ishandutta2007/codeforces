#include<bits/stdc++.h>
using namespace std;
struct node
{int L,R;long long val;};
int n,t,ans;
long long a[200005];
vector<node> vec1,vec2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        vec1.clear();
        scanf("%d",&n);
        scanf("%lld",&a[1]);
        for(int i=1;i<=n-1;i++)
        {
            scanf("%lld",&a[i+1]);
            long long x=a[i]-a[i+1];
            if(x<0) x=-x;
            vec1.push_back((node){i,i,x});
            vec2.clear();
            for(auto &p : vec1)
            {
                long long tmp=__gcd(p.val,x);
                if(tmp!=1) ans=max(ans,i-p.L+1);
                if(!vec2.empty() && vec2.back().val==tmp)
                {
                    vec2[vec2.size()-1].R=p.R;
                }
                else
                {
                    vec2.push_back((node){p.L,p.R,tmp});
                }
            }
            vec1=vec2;
        }
        if(n==1) printf("1\n");
        else printf("%d\n",ans+1);
    }
}