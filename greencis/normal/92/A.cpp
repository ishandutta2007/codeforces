#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    bool ok = false;
    while(!ok) {
        for (int i = 1; i <= n; ++i) {
            if (m < i) {
                ok = true;
                break;
            }
            m -= i;
        }
    }
    cout << m;
    return 0;
}