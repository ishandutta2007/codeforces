#include <iostream>

using namespace std;

int main()
{
int n;
cin >> n;
int t = n/2;
for(int i = 0; i < n; i++)
{
for(int j = 0; j < n; j++)
{
if(abs(i-t)+abs(j-t) <= t) cout << 'D';
else cout << '*';
}
cout << endl;
}
return 0;
}