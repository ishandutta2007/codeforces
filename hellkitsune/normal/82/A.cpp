#include <iostream>
#include <cmath>

using namespace std;

const float EPS = 1e-7;

int main()
{
    const char *s[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

    int n;

    cin >> n;

    --n;

    int k = log(n / 5.0f + 1.0f) / log(2.0f) + EPS;

    cout << s[int((n - (pow(2.0f, k) - 1.0f) * 5.0f) / pow(2.0f, k) + EPS)] << endl;
}