#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
 
using namespace std;
 
 
#define MAXN 1000000

 
int main(){
    int n;
    cin >> n;
    int a[100000];
    a[0] = 0;
    a[1] = 1;
    int i = 0;
    while(a[i] < n){
    	i++;
    	if(i > 1){
    		a[i] = a[i - 1] + a[i - 2];
    	}
    }
    if(i == 2 || i == 1){
    	printf("0 0 1");
    	return 0;
    }
    if(i == 0){
    	printf("0 0 0");
    	return 0;
    }
    if(i == 3){
    	printf("0 1 1");
    	return 0;
    }
    printf("%d %d %d\n", a[i - 1], a[i - 3], a[i - 4]);
    return 0;
}