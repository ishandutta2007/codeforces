#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <cmath>

#define x first
#define y second
 
using namespace std;

int main(){
    
    pair<int, int> p;
    double x;
    double y = 1283;
    cin >> x;
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 11; j++){
            if (fabs(x - i * j / sqrtl(4 * i * i + j * j)) < y){
                p = make_pair(i, j);
                y = fabs(x - i * j / sqrtl(4 * i * i + j * j));
            }
        }
    }
    cout << p.y << " " << p.x << "\n";
    
    return 0;
}