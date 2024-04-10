#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
    int n , a[100];
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
    	scanf("%d", &a[i]);
    }
    for(int i = 0; i<n; i++){
    	bool b = true;
    	for(int j = 0; j<n; j++){
    		if(a[i] % 2 == a[j] % 2 && i != j){
                 b = false;
                 break;
    		}
    	}
    	if(b){
    		printf("%d\n", i + 1);
    		return 0;
    	}
    }
    return 0;
}