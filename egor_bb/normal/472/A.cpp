#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;


int n, a, b;


int main(){
	cin >> n;
	for (int i = 4; i < n; i++){
		bool flag = false;
		for (int j = 2; j * j <= i; j++){
			if (i % j == 0){
				flag = true; break;
			}
		}
		if (flag){
			for (int j = 2; j * j <= (n - i); j++){
				if ((n - i) % j == 0){
					cout << i << " " << n - i;
					return 0;
				}
			}
		}
	}

}