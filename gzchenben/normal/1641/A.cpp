#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,t;
long long x,a[200005];
multiset<long long> st;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        st.clear();
        scanf("%d%lld",&n,&x);
        for(int i=1;i<=n;i++)   
        {
            scanf("%lld",&a[i]);
            st.insert(a[i]);
        }
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            auto It=st.find(a[i]);
            if(It==st.end()) continue;
            auto It2=st.find(a[i]*x);
            if(It2==st.end()) continue;
            st.erase(It);
            st.erase(It2);
            ans++;
        }
        printf("%d\n",n-2*ans);
    }
}