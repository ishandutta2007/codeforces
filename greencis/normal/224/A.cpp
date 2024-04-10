#include <iostream>
#include <cmath>
using namespace std;
long long a,b,c,s;
int main()
{
    cin>>a>>b>>c;
    s = sqrt(a*b*c);
    cout << 4*(s/a+s/b+s/c);
    return 0;
}