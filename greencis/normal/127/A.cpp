#include <iostream>
#include <cmath>
using namespace std;

int n,k,x,y,x2,y2;
double dist;

int main()
{
    cin >> n >> k >> x >> y;
    while (--n) {
        cin >> x2 >> y2;
        dist += sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
        x = x2; y = y2;
    }
    cout.precision(17);
    cout << fixed << dist * k / 50.;
    return 0;
}