#include <iostream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int i, r = 0;
    cin >> i;
    while (i != 0)
    {
        if (i % 2 == 1) r++;
        i /= 2;
    }
    cout << r;
    return 0;
}