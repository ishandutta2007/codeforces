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
    scanf("%d", &n);
    int k = n / 36;

    n = n % 36;
    int l = n / 3;
    n = n % 3;
    if(n == 2){
    	l++;
    }
    if (l == 12){
    	k++;
    	l = 0;
    }
    printf("%d %d\n", k, l);

	return 0;
}