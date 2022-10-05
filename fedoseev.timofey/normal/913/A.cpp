#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    if (n > 30) {
        cout << m << endl;
    }
    else {
        int md = (int)pow(2, n);
        cout << m % md << endl;
    }
}