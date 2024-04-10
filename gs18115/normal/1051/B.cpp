#include<iostream>
using namespace std;
typedef long long LL;
LL i,X,Y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>X>>Y;
    cout<<"YES"<<endl;
    for(i=X;i<Y;i+=2)
        cout<<i<<' '<<i+1<<'\n';
    cout<<endl;
    return 0;
}