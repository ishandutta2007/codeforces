
#include <iostream>
using namespace std;

int main()
{
int n;
cin >> n;
int sum = 0;
for(int i = 1; i <= n; i++) sum ^= i;
int x;
for(int i = 1; i < n; i++)
{
cin >> x;
sum ^= x;
}
cout << sum << endl;
return 0;
}