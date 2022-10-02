#include <iostream>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;




int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    cout << (1 != a && 1 != b ? 1: 2 != a && 2 != b ? 2: 3) << endl;
    return 0;
}