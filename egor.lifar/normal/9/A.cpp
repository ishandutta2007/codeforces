#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
    int y, w;
    scanf("%d %d", &w, &y);
    int a = 6 - max(y, w) + 1;
    if(a == 6){
    	printf("1/1\n");
    } 
    if(a == 5){
    	printf("5/6\n");
    }
    if(a == 4){
    	printf("2/3\n");
    }
    if(a == 3){
    	printf("1/2\n");
    }
    if(a == 2){
    	printf("1/3\n");
    }
    if(a == 1){
    	printf("1/6");
    }
	return 0;
}