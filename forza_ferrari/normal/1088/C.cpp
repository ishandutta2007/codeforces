#include<iostream>
#include<cstdio>
using namespace std;
int n,a[2001];
int main()
{
    cin>>n;
    cout<<n+1<<'\n';
    for(int i=1;i<=n;++i)
        cin>>a[i];
    cout<<"1 "<<n<<" 100000\n";
    for(int i=1;i<=n;++i)
        cout<<"2 "<<i<<" "<<a[i]+100000-i+1<<'\n';
    return 0;
}