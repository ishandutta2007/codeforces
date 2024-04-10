#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
	string s;
	cin >> s;
	if(s.size() == 1){
		printf("0");
		return 0;
	}
    int n = 1;
    int k = 0;
    int l = s.size();
    for(int i = 0; i < l; i++){
       k += s[i] - '0';
    }
    while(k / 10 >= 1){
    	int k2 = 0;
    	while(k > 0){
    		k2 += (k % 10);
            k = k / 10;
    	}
    	n++;
    	k = k2;
    }
    printf("%d\n", n);
	return 0;
}