#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << 1+(k-1)/(2*m) << " " << 1+((k-1)%(2*m))/2 << " " << ((k%2) ? "L" : "R") << endl;
    return 0;
}