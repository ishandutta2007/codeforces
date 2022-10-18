#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int t,n,a,b,lst,l,r;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(abs(a-b)>1||a+b>n-2)
        {
            puts("-1");
            continue;
        }
        lst=0;
        l=1,r=n;
        if(a<=b)
        {
            cout<<n<<" ";
            lst=n;
            --r;
            while(a||b)
            {
                if(b)
                {
                    cout<<(lst=l++)<<" ";
                    --b;
                }
                if(a)
                {
                    cout<<(lst=r--)<<" ";
                    --a;
                }
            }
        }
        else
        {
            cout<<1<<" ";
            lst=1;
            ++l;
            while(a||b)
            {
                if(a)
                {
                    cout<<(lst=r--)<<" ";
                    --a;
                }
                if(b)
                {
                    cout<<(lst=l++)<<" ";
                    --b;
                }
            }
        }
        if(lst<l)
            for(int i=l;i<=r;++i)
                cout<<i<<" ";
        else        
            for(int i=r;i>=l;--i)
                cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}