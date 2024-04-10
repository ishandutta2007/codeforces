#include <stdio.h>
#include <string.h>
#include <vector>
#include <map> 
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <sstream>
 
using namespace std;
 
int a,b,c,d,q;
vector<int> v;

int main() {
    scanf("%d %d %d", &a, &b, &q);
    int g = __gcd(a,b);
    for (int i = 1; i*i <= g; i++) {
        if (g%i==0) {
            v.push_back(i);
            v.push_back(g/i);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &c, &d);
        vector<int>::iterator iter = lower_bound(v.begin(),v.end(),d+1);
        if (iter != v.begin() && *(--iter) >= c) {
            printf("%d\n", *iter);
        }
        else printf("-1\n");
    }
    
}