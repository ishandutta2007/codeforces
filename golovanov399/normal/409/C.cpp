#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define x first
#define y second
 
using namespace std;

int main(){
    
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    c /= 2;
    d /= 7;
    e /= 4;
    cout << min(a, min(b, min(c, min(d, e))));
    
    return 0;
}