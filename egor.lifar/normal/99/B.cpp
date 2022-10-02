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

int main() {
    int n;
    cin >> n;
    int a[1000];
    int k = 0;
    for(int i = 0; i < n; i++){
    	cin >> a[i]; 
    	k += a[i];  	
    } 
    if(k % n != 0){
    	printf("Unrecoverable configuration.\n");
    	return 0;
    }
    int b = k / n;
    int s = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] != b){
    		s++;
    	}
    }
    if(s == 0){
    	printf("Exemplary pages.\n");
    	return 0;
    }
    if(s != 2){
    	printf("Unrecoverable configuration.\n");
    	return 0;
    }
    int x, y, z, g, j;
    for(int i = 0; i < n; i++){
    	if(a[i] > b){
    		g = i + 1;
    		x = a[i];
    	}
    	if(a[i] < b){
    		j = i + 1;
    		y = a[i];
    	}
    }
    z = x - b;
    printf("%d ml. from cup #%d to cup #%d.", z, j, g);
	return 0;
}