#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,v;
    cin>>n>>v;
    int ans=0;
    if(n-1-v>0)
    {
        for(int i=n-v;i>1;i--) ans+=i;
        ans+=v;
    }
    else ans=n-1;
    cout<<ans;
    return 0;
}