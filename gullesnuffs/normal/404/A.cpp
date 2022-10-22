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

char field[305][305];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%s", field[i]);
	bool ok=1;
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			if(i == j || i == n-1-j){
				if(field[i][j] != field[0][0])
					ok=0;
			}
			else{
				if(field[i][j] != field[1][0])
					ok=0;
			}
		}
	if(field[0][0] == field[1][0])
		ok=0;
	puts(ok?"YES\n":"NO\n");
	return 0;
}