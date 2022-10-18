#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
struct node
{
    int val,pos;
    bool operator <(const node &other) const
    {
        return val<other.val;
    }
}a[1001];
inline bool prime(int x)
{
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    for(register int i=2;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(register int i=1;i<=n;++i)
        {
            cin>>a[i].val;
            sum+=a[i].val;
            a[i].pos=i;
        }
        if(!prime(sum))
        {
            cout<<n<<endl;
            for(register int i=1;i<=n;++i)
                cout<<i<<" ";
            cout<<endl;
            continue;
        }
        cout<<n-1<<endl;
        sort(a+1,a+n+1);
        for(register int i=1;i<=n;++i)
            if(!prime(sum-a[i].val))
            {
                for(register int j=1;j<=n;++j)
                    if(i^j)
                        cout<<a[j].pos<<" ";
                break;
            }
        cout<<endl;
    }
    return 0;
}