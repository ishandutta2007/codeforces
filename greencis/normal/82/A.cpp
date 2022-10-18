#include <iostream>
using namespace std;

int main()
{
    string p[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int k;
    cin >> k;
    int d = 1;

    for (k--; k-5*d>=0; ) {
        k-=5*d;
        d*=2;
    }
    cout<<p[k/d];
    return 0;
}