#include<iostream>
//#include<cstdlib>
using namespace std;
int a,b,sum,c,d;
int main()
{
    cin>>a>>b;
    c=a/b;
    sum=a;
    while(c>0)
    {
          sum+=c;
          d=a%b;
          a=c+d;
          c=a/b;
    }
    cout<<sum;
//    system("pause");
    return 0;
}