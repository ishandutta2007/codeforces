#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back

int main(){
	int m, r;
	double sum = 0;
	cin >> m >> r;
	for (int i=0; i<m; ++i){
		sum += 2.0 * (m - i - 1) * i;
		if (i == 1) sum += 1.0 * (m - i) * (sqrt(2.0) + 2);
		else if (i > 1) sum += 2.0 * (m - i) * sqrt(2.0);
		else sum += m * 1.0;
	}
	sum *= r * 2;
	sum /= 1.0 * m * m;
	printf("%.9lf\n", sum);
	return 0;
}