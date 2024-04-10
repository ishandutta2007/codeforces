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
    scanf("%d", &n);
    int a[100000], b[100000];
    for(int i = 0; i < n; i++){
    	scanf("%d %d", &a[i], &b[i]);
    }
    int k = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(i != j && a[i] == b[j]){
            	k++;
    		}
    	}
    }
    printf("%d\n", k);   
    return 0;
}