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
#include <cassert>
using namespace std;

long long x;
int n, d;

long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

int a[100005];
int b[100005];
int ainv[100005];

void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
	scanf("%d%d%I64d", &n, &d, &x);
	initAB();
	for(int i=0; i < n; ++i){
		ainv[a[i]]=i;
	//	printf("%d ", a[i]);
	}
	/*printf("\n");
	for(int i=0; i < n; ++i)
		printf("%d ", b[i]);
	printf("\n");*/
	vector<int> bs;
	for(int i=0; i < n; ++i)
		if(b[i])
			bs.push_back(i);
	for(int i=0; i < n; ++i){
	if(d > 350){
		int j;
		for(j=n-1; j >= 0 && (i-ainv[j] < 0 || b[i-ainv[j]] == 0); --j);
		printf("%d\n", j+1);
	}
	else{
		int best=0;
		for(int j=0; j < bs.size(); ++j){
			if(i-bs[j] >= 0)
				best=max(best, a[i-bs[j]]+1);
		}
		printf("%d\n", best);
	}
	}
	return 0;
}