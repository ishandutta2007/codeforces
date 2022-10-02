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

int r[10000];
 
int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    r[a] = 1;
    r[b] = 1;
    r[c] = 1;
    for(int i = 0; i <= n; i++){
    	if(i >= a && r[i - a] > 0){
    		r[i]++;
    		r[i] = max(r[i], r[i - a] + 1);
    	}
    	if(i >= b && r[i - b] > 0){
    		r[i] = max(r[i], r[i - b] + 1);
    	}
    	if(i >= c && r[i - c]){
    		r[i] = max(r[i], r[i - c] + 1);
    	}
    }
    printf("%d", r[n]);
    return 0;
}