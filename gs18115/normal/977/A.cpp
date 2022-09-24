#include<bits/stdc++.h>
using namespace std;
int n,k,i;
int main()
{
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        if(n%10==0)
            n/=10;
        else
            n--;
    }
    cout<<n<<endl;
    return 0;
}