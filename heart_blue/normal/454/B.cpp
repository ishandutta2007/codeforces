#include <iostream>
using namespace std;
const int N = 1e5;
int a[N];
int main()
{
int n;
cin >> n;
for(int i = 0; i < n; i++)
{
cin >> a[i];
}
int cnt = 1;
int k = -1;
for(int i = 1; i < 2*n; i++)
{
    if(a[i%n] >= a[(i-1)%n]) cnt++;
    else cnt = 1;
    if(cnt == n)
    {
         k = (n - i - 1 + n)%n;
         break;
    }
}
if(n == 1) k = 0;
cout << k << endl;
return 0;
}