#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
n/=1000;
if(n==6||n==11)cout<<3<<endl;
else if(n==8||n==9)cout<<2<<endl;
else cout<<1<<endl;
}