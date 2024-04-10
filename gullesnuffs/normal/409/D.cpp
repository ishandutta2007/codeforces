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

int val[]={1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", val[n-1]);
	return 0;
}