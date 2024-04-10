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

using namespace std;

map<int, int> l, r;
int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    int t[100000];
    for(int i = 0; i < m; i++){
    	cin >> t[i];
    	cin >> l[t[i]] >> r[t[i]];
    }
    int x = s;
    int b;
    int y = 0;
    if(s < f){
    	b = 1;
    }else{
    	b = -1;
    }
    while(x != f){
    	if((l.find(y + 1) != l.end() && !(l[y + 1] <= x && r[y + 1] >= x) && !(l[y + 1] <= x + b && r[y + 1] >= x + b)) || l.find(y + 1) == l.end()){
    		x += b;
    		if(b < 0){
    			printf("L");
    		}else{
    			printf("R");
    		}
    	}else {
    		printf("X");
    	}
  		y++;
    }
    printf("\n");
	return 0;
}