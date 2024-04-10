#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000111;

int main()
{
#ifdef DEBUG
    //freopen("in.txt", "r", stdin);
#endif
    long long i;
    cin >> i;
    if (i%2) {
        cout << -1-i/2;
    } else {
        cout << i/2;
    }
    return 0;
}