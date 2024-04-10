#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

set <int> s;
int a,flag=0;

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        s.insert(a);
    }

    vector<int> v(s.begin(),s.end());

    if(v.size() == 3) {
       int m = v[0] + (v[2]-v[0])/2;
       if (m == v[1] && m - v[0] == v[2] - m) flag = 1;
    }
    else if(v.size() < 3) flag = 1;


    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}