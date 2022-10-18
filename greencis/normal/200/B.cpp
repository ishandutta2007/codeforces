#include <iostream>

using namespace std;

int main()
{
    double n,res=0,t;
    cin>>n;
    for(int i = 0; i <n;++i)
        cin>>t,res+=t;
    cout.precision(9);
    cout<<fixed<<res/n;
    return 0;
}