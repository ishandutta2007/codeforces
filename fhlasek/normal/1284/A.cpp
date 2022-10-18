/* Written by Filip Hlasek 2019 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 22
string a[MAXN], b[MAXN];
int A, B;

int main(int argc, char *argv[]) {
  cin >> A >> B;
  REP(i, A) cin >> a[i];
  REP(i, B) cin >> b[i];
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int Y;
    scanf("%d", &Y);
    Y--;
    cout << a[Y % A] << b[Y % B] << endl;
  }
	
	return 0;
}