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

vector<int > vii;

int main(){
	int x, k;
	scanf("%d%d", &x, &k);
	for(int i=0; i < k; ++i){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int a, b;
			scanf("%d%d", &a, &b);
			vii.push_back(a);
			vii.push_back(b);
		}
		else{
			int a;
			scanf("%d", &a);
			vii.push_back(a);
		}
	}
	vii.push_back(0);
	vii.push_back(x);
	sort(vii.begin(), vii.end());
	int Min=0, Max=0;
	for(int i=0; i < vii.size()-1; ++i){
		Min += (vii[i+1]-vii[i])/2;
		Max += vii[i+1]-vii[i]-1;
	}
	printf("%d %d\n", Min, Max);
	return 0;
}