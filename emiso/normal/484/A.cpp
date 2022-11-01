//aprendi com thebeauty
#include <stdio.h>
#include <iostream>

using namespace std;

long long c=0,l,r;

int main()
{
    int n;
    cin >> n;
    while(n--) {
         c=0;
         cin >> l >> r;
         r++;
         for(int i=62;i>=0;i--) {
                 int x = (l & (1LL<<i)) != 0;
                 int y = (r & (1LL<<i)) != 0;
                 if(x==y) c |= (l&(1LL<<i));
                 else c |= ((1LL<<i)-1);
         }
         cout << c << endl;
    }
    return 0;
}
//admito quase copiei dele