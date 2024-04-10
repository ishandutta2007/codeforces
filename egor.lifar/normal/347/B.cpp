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

int main() {
	int n;
	int a[100000];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int d = 0;
	int l = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == i){
			d++;
		}else {
			if(a[a[i]] == i){
				l = max(l, 2);
			}else{
				l = max(l, 1);
			}
		}
	}
	cout << d + l << endl;
}