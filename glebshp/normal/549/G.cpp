#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

const int size = 2000 * 1000 + 1000;
int n;

int a[size];	

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    vector <int> vec;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    	vec.pb(a[i] + i);
    }

    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    	vec[i] -= i;
   	for (int i = 0; i < n - 1; i++)
   		if (vec[i] > vec[i + 1]) {
   			printf(":(");
   			return 0;
   		}	

   	for (int i = 0; i < n; i++)
   		printf("%d%c", vec[i], " \n"[i == n - 1]);

    return 0;
}