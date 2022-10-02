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
    int n, m;
    cin >> n >> m;
    int k = min(n, m);
    int s = 0;
    for(int i = 0; i <= k; i++){
    	for(int j = 0; j <= k; j++){
    		if(i * i + j == n && j * j + i == m){
    			s++;
    		}
    	}
    }
    printf("%d\n", s);
    return 0;
}