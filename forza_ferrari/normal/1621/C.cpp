#include<iostream>
#include<cstdio>
using namespace std;
int t,n,p[10001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            p[i]=0;
        for(int i=1;i<=n;++i)
            if(!p[i])
            {
                int fst=-1,lst=-1;
                while(1)
                {
                    cout<<"? "<<i<<endl;
                    int x;
                    cin>>x;
                    if(~lst)
                        p[lst]=x;
                    lst=x;
                    if(fst==-1)
                        fst=x;
                    else if(fst==x)
                        break;
                }
            }
        cout<<"! ";
        for(int i=1;i<=n;++i)
            cout<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}