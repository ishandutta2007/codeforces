#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
    int n, a[1000], d;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    int k = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(i != j && abs(a[i] - a[j]) <= d) {
                k++;
    		}
    	}
    	
    }
    printf("%d\n", k);
    
	return 0;
}