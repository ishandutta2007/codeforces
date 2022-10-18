#include<iostream>
#include<cstdio>
using namespace std;
int t,n,maxn,l,r;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a=2,b=3;
        cout<<"? 1 2 3"<<endl;
        cin>>maxn;
        for(int i=3;i<=n;++i)
        {
            cout<<"? 1 2 "<<i<<endl;
            int tmp;
            cin>>tmp;
            if(tmp>maxn)
            {
                b=i;
                maxn=tmp;
            }
        }
        for(int i=3;i<=n;++i)
        {
            if(i==b)
                continue;
            cout<<"? 1 "<<i<<" "<<b<<endl;
            int tmp;
            cin>>tmp;
            if(tmp>maxn)
            {
                a=i;
                maxn=tmp;
            }
        }
        if(a!=2)
        {
            cout<<"! "<<a<<" "<<b<<endl;
            continue;
        }
        else
        {
            cout<<"? "<<a<<" "<<b<<" "<<(b==n? n-1:n)<<endl;
            int tmp;
            cin>>tmp;
            if(tmp>=maxn)
                cout<<"! "<<a<<" "<<b<<endl;
            else
            {
                cout<<"? 1 "<<b<<" "<<(b==n? n-1:n)<<endl;
                int tmp;
                cin>>tmp;
                if(tmp>=maxn)
                    cout<<"! 1 "<<b<<endl;
                else
                    cout<<"! 1 "<<a<<endl;
            }
        }
    }
    return 0;
}