#include<iostream>
#include<cstdio>
using namespace std;
int t,n,p[10001],pos,pre;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(register int i=1;i<=n;++i)
            p[i]=0;
        pos=0;
        pre=1;
        for(register int i=1;i+1<=n;i+=2)
        {
            cout<<"? 2 "<<i<<" "<<i+1<<" 1"<<endl;
            int val;
            cin>>val;
            if(val==1)
            {
                p[i]=1;
                pos=i;
                break;
            }
            if(val==2)
            {
                cout<<"? 2 "<<i+1<<" "<<(i+1==n? 1:i+2)<<" 1"<<endl;
                cin>>val;
                if(val==1)
                {
                    p[i+1]=1;
                    pos=i+1;
                    break;
                }
            }
        }
        if((n&1)&&!pos)
        {
            p[n]=1;
            pos=n;
        }
        if(pos==1)
            pre=2;
        for(register int i=1;i<n;++i)
        {
            cout<<"? 1 "<<pos<<" "<<pre<<" "<<n-1<<endl;
            int val;
            cin>>val;
            p[pre]=val;
            while(pre<=n&&p[pre])
                ++pre;
        }
        cout<<"! ";
        for(register int i=1;i<=n;++i)
            cout<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}