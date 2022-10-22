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

int b[]={1, 1, 2, 7, 4};

int main(){
	int a[5];
	for(int i=0; i < 5; ++i)
		scanf("%d", a+i);
	int j;
	for(j=1; true; ++j){
		bool ok=1;
		for(int k=0; k < 5; ++k)
			if(b[k]*j > a[k])
				ok=0;
		if(!ok)
			break;
	}
	printf("%d\n", j-1);
	return 0;
}