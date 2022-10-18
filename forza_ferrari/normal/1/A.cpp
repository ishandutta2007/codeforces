#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    cout<<(long long)(ceil(n*1.0/a)*ceil(m*1.0/a))<<endl;
    return 0;
}