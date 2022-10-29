#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double f=(a*d)/(b*d-(b-a)*(d-c));
     std::cout << std::fixed;
    std::cout << std::setprecision(12);
    std::cout << f;
    return 0;
}