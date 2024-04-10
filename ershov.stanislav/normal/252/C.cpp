#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long n, j=0, d, ans=0;
vector<int> v(111111);
int main()
{
    cin >> n >> d;
    for (long long i=0; i<n; i++) cin >> v[i];
    for (long long i=0; i<n; i++) {
        while (v[j]<v[i]-d)j++;
        ans+=(i-j)*(i-j-1)/2;
    }
    cout << ans;
    return 0;
}