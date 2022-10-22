#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

char input[1000005];

int main(){
	scanf("%s", input);
	int len=strlen(input);
	if(input[len-1] == 'R')
		for(int i=0; i < len; ++i){
			if(input[i] == 'L')
				input[i]='R';
			else
				input[i]='L';
		}
	int Min=0, Max=10000000;
	while(Max-Min > 1){
		int test=(Max+Min)/2;
		int p=0;
		int minP=0;
		for(int i=0; i < len-1; ++i){
			if(input[i] == 'L'){
				--p;
				if(p < minP)
					minP=p;
			}
			else{
				++p;
				if(p >= test)
					p=test-1;
			}
		}
		if(minP < p)
			Max=test;
		else
			Min=test;
	}
	if(Min > 5000000)
		Min=1;
	printf("%d\n", Min);
	return 0;
}