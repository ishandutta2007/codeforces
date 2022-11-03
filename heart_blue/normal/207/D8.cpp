#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
n/=1000;
if(n&1)cout<<2<<endl;
else cout<<1<<endl;
}