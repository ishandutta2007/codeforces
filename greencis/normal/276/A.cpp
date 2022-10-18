#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int r = -2e9;
    while (n--) {
        int f,t;
        cin>>f>>t;
        r = max(r,(t>k?f+k-t:f));
    }
    cout << r;
    return 0;
}