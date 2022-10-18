#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;



int main()
{
    int n,k,l,r,sa,sk;
    cin>>n>>k>>l>>r>>sa>>sk;
    sa -= sk;
    n-=k;
    while (k > 0) {
        cout << sk / k << " ";
        sk-=sk/k;
        --k;
    }

    while (n > 0) {
        cout << sa / n << " ";
        sa-=sa/n;
        --n;
    }


    return 0;
}