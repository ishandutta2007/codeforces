#include<iostream>
#include<cstdlib>
using namespace std;
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(b,a%b)*b;}
int main()
{
    int n1,n2,n3,n4,d;
    cin>>n1>>n2>>n3>>n4>>d;
    cout<<d/n1+d/n2+d/n3+d/n4
          -d/lcm(n1,n2)-d/lcm(n1,n3)-d/lcm(n1,n4)-d/lcm(n2,n3)-d/lcm(n2,n4)-d/lcm(n3,n4)
          +d/lcm(lcm(n1,n2),n3)+d/lcm(lcm(n1,n2),n4)+d/lcm(lcm(n1,n3),n4)+d/lcm(lcm(n2,n3),n4)
          -d/lcm(lcm(lcm(n1,n2),n3),n4);
    return 0;
}