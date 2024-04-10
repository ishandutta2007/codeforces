#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;

int main(){
    int n, x[1000], y[1000];
    cin >> n;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    	a += x[i];
    	b += y[i];
    }
    if(a % 2 != b % 2){
    	cout << "-1\n";
    }else{
    	if(a % 2 == 0 && b % 2 == 0){
    		cout << "0\n";
    		return 0;
    	}
    	for(int i = 0; i < n; i++){
    		if(x[i] % 2 != y[i] % 2){
    			cout << "1\n";
    			return 0;
    		}
    	}
    	cout << "-1\n";
    }
	return 0;
}