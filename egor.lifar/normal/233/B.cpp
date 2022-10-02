#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>

using namespace std;

int s(int x){
	int n = 0;
	while(x > 0){
		n += x % 10;
		x = x / 10;
	}
	return n;
}
int main() {
	long long n;
	cin >> n;
    for(int i = 1; i < 9 * 19; i++){
    	long long d = i * i + 4 * n;
    	double x = sqrt(d);
    	double y = (x - i) / 2;
    	long long a = (long long)(y + 0.00000001);
    	if(a > 0 && i == s(a) && a * a + i * a - n == 0){
    		cout << a << "\n";
    		return 0;
    	}
    }
    cout << "-1" << "\n";
	return 0;
}