#include <iostream>
using namespace std;
int main ()
{
    int farhod1,farhod2,farhod3;
    cin>>farhod1>>farhod2>>farhod3;
    cout<<(farhod1*farhod2)+(farhod2*farhod3)+(farhod1*farhod3)-(farhod1+farhod2+farhod3-1);
}