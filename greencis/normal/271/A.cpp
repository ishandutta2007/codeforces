#include <iostream>

using namespace std;

int main()
{
    int y;
    cin >> y;
    int ok = 1;
    while (ok) {
        ++y;
        int freq[10]={};
        int x = y;
        int ok1 = 1;
        while (x) {
            freq[x%10]++;
            if (freq[x%10] == 2)
            {
                ok1 = 0;
                break;
            }
            x/=10;
        }
        if (ok1) break;
    }
    cout << y;
    return 0;
}