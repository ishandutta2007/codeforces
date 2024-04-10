#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n / 2 - 1; i++){
    	printf("%c%c-", s[2 * i], s[2 * i + 1]);
    }
    for(int i = (n / 2 - 1) * 2; i<n; i++){
    	printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}