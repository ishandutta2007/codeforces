#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n,a;
    scanf("%d",&n);

    set<int> s;
    set<int>::reverse_iterator rit;

    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        s.insert(a);
    }

    int flag = 1;
    while(flag) {
        flag = 0;

        int x = *(s.rbegin());
        while(1) {
            if(x/2 && !s.count(x/2)) {
                s.erase(x);
                s.insert(x/2);

                flag = 1;
                break;
            }
            else if(x/2) {
                x = x/2;
            }
            else break;
        }
    }

    for(auto i: s) printf("%d ",i);
    return 0;
}