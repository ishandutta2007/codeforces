#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<2*(n/3+n/2)+n<<'\n';
    }
    return 0;
}