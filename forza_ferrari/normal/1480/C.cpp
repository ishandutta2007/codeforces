#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int n,a,b,c;
int main()
{
    srand(time(NULL));
    cin>>n;
    if(n==1)
    {
        cout<<"! 1"<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<"? 1"<<endl;
        cin>>a;
        cout<<"? 2"<<endl;
        cin>>b;
        if(a>b)
            cout<<"! 2"<<endl;
        else
            cout<<"! 1"<<endl;
        return 0;
    }
    int l=1,r=n;
    for(register int i=1;i<=33;++i)
    {
        int p=rand()%(r-l+1)+l;
        if(p==1)
        {
            cout<<"? 1"<<endl;
            cin>>a;
            cout<<"? 2"<<endl;
            cin>>b;
            if(a<b)
            {
                cout<<"! 1"<<endl;
                return 0;
            }
            else
                l=2;
            continue;
        }
        if(p==n)
        {
            cout<<"? "<<n<<endl;
            cin>>a;
            cout<<"? "<<n-1<<endl;
            cin>>b;
            if(a<b)
            {
                cout<<"! "<<n<<endl;
                return 0;
            }
            else
                r=n-1;
            continue;
        }
        cout<<"? "<<p-1<<endl;
        cin>>a;
        cout<<"? "<<p<<endl;
        cin>>b;
        cout<<"? "<<p+1<<endl;
        cin>>c;
        if(a>b&&b<c)
        {
            cout<<"! "<<p<<endl;
            return 0;
        }
        else
            if(a<b)
                r=p-1;
            else
                l=p+1;
    }
    return 0;
}