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
const int size = 1000 * 1000 + 100;

bool prime[size];
int n;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 2; i < size; i++)
    	prime[i] = true;
   	for (int i = 2; i * i < size; i++) {
   		if (prime[i]) {
   			for (int j = i; i * j < size; j++)
   				prime[i * j] = false;
   		}
   	}

   	for (int i = 0; i < size; i++)
   		if (prime[i]) {
   			int h = i;
   			while (h < size) {
   				prime[h] = true;
   				if (h > size / i)
   					break;
   				h *= i;
   			}
   		}

   	int cnt = 0;
    for (int i = 2; i <= n; i++)
    	cnt += prime[i];

   	printf("%d\n", cnt);
   	for (int i = 0; i <= n; i++)
   		if (prime[i])
   			printf("%d ", i);

    return 0;
}