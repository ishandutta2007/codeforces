#include<iostream>
using namespace std;
int n,m;
int a,s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s+=a;
        cout<<s/m<<' ';
        s%=m;
    }
    return 0;
}