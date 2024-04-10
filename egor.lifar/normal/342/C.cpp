    
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;


int r, h;


int main() {
    cin >> r >> h;
    int c = 0;
    if (h % r >= (r + 1) / 2) {
        c++;
    }
    if (h % r >= r - r / 7) {
        c++;
        //cout << "o[a" << endl;
    }
    cout << c + 1 + (h / r) * 2 << endl;
    return 0;
}