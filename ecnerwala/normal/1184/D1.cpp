#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 55;

int N, K, M, T;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> M >> T;
    for (int t = 0; t < T; t++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            if (b >= K)
            {
                N = b;
            }
            else
            {
                K -= b;
                N -= b;
            }
        }
        else
        {
            if (b <= K)
                K++;
            N++;
        }
        cout << N << " " << K << "\n";
    }
}