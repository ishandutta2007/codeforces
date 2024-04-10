#include<iostream>
#include<fstream>
using namespace std;
typedef long long LL;
typedef long double LD;
inline void sync()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return;
}
int i;
int main()
{
    sync();
    for(i=0;i<1000;i++)
        cout<<5;
    cout<<endl;
    for(i=1;i<1000;i++)
        cout<<4;
    cout<<5<<endl;
    return 0;
}