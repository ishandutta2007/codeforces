#include<iostream>
using namespace std;
typedef long long LL;
inline LL query(LL X,LL Y)
{
    cout<<"? "<<X<<' '<<Y<<endl;
    cin>>X;
    return X;
}
inline void answer(LL X,LL Y)
{
    cout<<"! "<<X<<' '<<Y<<endl;
    return;
}
LL i,X,Y;
bool flag1,flag2;
LL t,T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=30;i-->0;)
    {
        if(flag2)
        {
            t=query(X+(1<<i),Y);
            if(t==-1)
            {
                X|=1<<i;
                Y|=1<<i;
            }
            continue;
        }
        else if(!flag1)
            t=query(X,Y);
        else
            t=-T;
        flag1=false;
        if(t==0)
        {
            flag2=true;
            t=query(X+(1<<i),Y);
            if(t==-1)
            {
                X|=1<<i;
                Y|=1<<i;
            }
            continue;
        }
        T=query(X+(1<<i)-1,Y+(1<<i)-1);
        if(T!=t)
        {
            flag1=true;
            t=query(X+(1<<i),Y);
            if(t==-1)
            {
                X|=1<<i;
                Y|=1<<i;
            }
        }
        else
        {
            if(t==1)
                X|=1<<i;
            else
                Y|=1<<i;
        }
    }
    answer(X,Y);
    return 0;
}