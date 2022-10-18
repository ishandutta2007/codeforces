#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;

int a,b,s;

int main()
{
 cin >> a >> b >> s;
 int dist = abs(a) + abs(b);
 if (dist <= s && (s - dist) % 2 == 0) cout << "Yes";
 else cout << "No";
 return 0;
}