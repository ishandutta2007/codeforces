#include<iostream>
using namespace std;
typedef long long LL;
void print(LL E,LL Y)
{
    LL L=E/Y;
    if(L==2)
        cout<<Y<<' '<<E;
    else if(L==3)
        cout<<Y<<' '<<Y<<' '<<E;
    else
    {
        if(L&1)
        {
            for(LL i=Y;i<=E;i+=Y*2)
                cout<<Y<<' ';
            print(E-Y,Y<<1);
        }
        else
        {
            for(LL i=Y;i<=E;i+=Y*2)
                cout<<Y<<' ';
            print(E,Y<<1);
        }
    }
    return;
}
LL N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N==1)
        cout<<1;
    else
        print(N,1);
    cout<<endl;
    return 0;
}