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
    int x;
    cin >> x;
    int k = (int)sqrt(x);
    bool b[10];
    for(int i = 0; i < 10; i++){
    	b[i] = false;
    }
    int t = x;
    while(t > 0){
    	b[t % 10] = true;
    	t = t / 10;
    }
    int s = 0;
    for(int i = 1; i <= k; i++){
    	if(x % i == 0){
    		bool r[10], g[10];
            int z = i;
            int y = x / i;
            for(int j = 0; j < 10; j++){
    			r[j] = false;
    			g[j] = false;
    		}
            while(z > 0){
            	r[z % 10] = true;
            	z = z / 10;
            }
            while(y > 0){
            	g[y % 10] = true;
            	y = y / 10;
            }
            for(int j = 0; j < 10; j++){
                if(b[j] && r[j]){
                	s++;
                	break;
                }
            }
            for(int j = 0; j < 10; j++){
                if(b[j] && g[j] && i != x / i){
                	s++;
                	break;
                }
            }
    	}
    }
    printf("%d\n", s);
	return 0;
}