#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
 

using namespace std;


int main() {
    vector<int> v, v2, v3;
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    v.push_back(0);
    v2.push_back(0);
    v.push_back(a);
    v2.push_back(b);
    for(int i = 1; i < t; i++){
    	a -= da;
    	b -= db;
        v.push_back(a);
        v2.push_back(b);
    }
    int k = v.size();
    int n = v2.size();
    for(int i = 0; i < k; i++){
    	for(int j = 0; j < n; j++){
    		v3.push_back(v2[j] + v[i]);
    	}
    }
    int l = v3.size();
    for(int i = 0; i < l; i++){
    	if(v3[i] == x){
    		printf("YES\n");
    		return 0;
    	}
    }
    printf("NO\n");
	return 0;
}