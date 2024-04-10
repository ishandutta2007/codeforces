#include<iostream>
#include<cstdio>
#include<random>
#include<chrono>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n,ans[3001],pos,val;
inline int calc(int x)
{
    int p,tmp=2047;
    for(int i=1;i<=15;++i)
    {
        p=rnd()%n+1;
        while(p==x)
            p=rnd()%n+1;
        cout<<"? "<<x<<" "<<p<<endl;
        int w;
        cin>>w;
        tmp&=w;
    }
    return tmp;
}
int main()
{
    cin>>n;
    pos=rnd()%n+1;
    val=calc(pos);
    for(int i=1;i<=n;++i)
    {
        if(i==pos)
            continue;
        cout<<"? "<<pos<<" "<<i<<endl;
        int w;
        cin>>w;
        if(w==val)
            val=calc(pos=i);
    }
    for(int i=1;i<=n;++i)
        if(i^pos)
        {
            cout<<"? "<<i<<" "<<pos<<endl;
            cin>>ans[i];
        }
    cout<<"! ";
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}