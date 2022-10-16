#include <fstream>
#include <iostream>
using namespace std;

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if (a + b < n + m || min(a, b) < m) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}