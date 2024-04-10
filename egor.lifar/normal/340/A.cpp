#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 

using namespace std;

long long nod(long long a, long long b){
	if(b == 0){
		return a;
	}
	nod(b,  a % b);
}
int main() {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    long long k = 0;
    long long s = (x * y) / nod(x, y);
    long long l = s * ((a + s - 1) / s);
    if(l > b){
    	printf("0");
    	return 0;
    }
    k = (b - l) / s + 1;
    cout << k << "\n";
   	return 0;
}