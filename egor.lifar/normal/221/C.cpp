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
    int n, a[100000], b[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	b[i] = a[i];
    }
    sort(b, b + n);
    int k = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] != b[i]){
    		k++;
    	}
    }
    if(k <= 2){
    	printf("YES\n");
    }else{
    	printf("NO\n");
    }
	return 0;
}