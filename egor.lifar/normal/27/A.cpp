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
	int a[3000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n+1; i++){
		bool b = true;
	    for(int j = 0; j < n; j++){
	        if(a[j] == i){
	        	b = false;
	        	break;
	        }
        }
        if(b){
        	printf("%d\n", i);
        	return 0;
        }
	}
	return 0;
}