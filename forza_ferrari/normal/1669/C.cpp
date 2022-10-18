#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int tag[2];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        tag[0]=tag[1]=-1;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(tag[i&1]==-1)
                tag[i&1]=x&1;
            else
                if(tag[i&1]^(x&1))
                    flag=0;
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}