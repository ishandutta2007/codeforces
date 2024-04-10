#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        for(int j=1;j<=n;++j)
            cout<<((j-i+n)%n*i%n+x)%n<<" ";
        cout<<'\n';
    }
    return 0;
}