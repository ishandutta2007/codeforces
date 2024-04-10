#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int s=0;
    while (n) {
        if (n%10==4)++s;
        if (n%10==7)++s;
        n/=10;
    }
    cout << ((s==4||s==7)?"YES":"NO");
    return 0;
}