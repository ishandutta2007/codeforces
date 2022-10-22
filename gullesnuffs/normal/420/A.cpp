#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

char input[100005];

int main(){
	scanf("%s", input);
	int len=strlen(input);
	bool ok=1;
	for(int i=0; i < len; ++i){
		char a=input[i], b=input[len-1-i];
		if(a == b){
			if(a == 'A' || a == 'H' || a == 'I' || a == 'M' || a == 'O' || a == 'T' || a == 'U' || a == 'V' || a == 'W' || a == 'X' || a == 'Y')
				continue;
		}
		ok=0;
	}
	puts(ok?"YES":"NO");
	return 0;
}