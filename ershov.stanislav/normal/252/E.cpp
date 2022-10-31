#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int lcd=2*2*2*3*3*5*7*11*13;
ll a, b, k, d[lcd], y=0, l, i;
int main()
{
    cin >> a >> b >> k;
    while(a>b) {
        for (i=2, l=1; i<=k; i++) if (a%i>l&&a-a%i>=b) l=a%i;
        y++; a-=l;
        if (d[a%lcd]) {
            int c=y-d[a%lcd];
            y+=c*((a-b)/lcd);
            a-=((a-b)/lcd)*lcd;
        }
        d[a%lcd]=y;
    }
    cout << y;
    return 0;
}