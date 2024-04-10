#include <iostream>

using namespace std;

int b[2000];
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        int mz;
        for (int j = 0; j < n; j++)
            if (!b[j]) { mz = j; break; }
        b[mz] = -1;
        cout << mz + 1 << " ";
        //cout << mz + 1 << endl;
        for (int j = 0; j < n; j++)
            if (b[j] > 0 && mz >= j + k) b[j]--;
        //for (int j = 0; j < n; j++) cout << b[j] << " "; cout << endl;
    }
}