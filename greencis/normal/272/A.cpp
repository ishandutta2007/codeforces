#include <iostream>

using namespace std;
int n,q,t,res=0;
int main()
{

    cin>>n;
    for(int i =0;i<n;++i){
        cin>>t;
        q+=t;
        q%=(n+1);
    }
    for (int i = 1; i < 6; ++i) {
        if ((q+i)%(n+1)!=1)++res;
    }
    cout<<res;
    return 0;
}