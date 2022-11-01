#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    cin>>N>>M;
    int ans=0, i=0;
    while(N>0)
    {
        N--;
        i++;
        if(i%M==0) N++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}