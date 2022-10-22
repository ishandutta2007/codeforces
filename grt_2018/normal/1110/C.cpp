#include <bits/stdc++.h>

using namespace std;

int q;
int T[27] = {1, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    while(q--) {
        int a;
        cin>>a;
        bool ok=0;
        int x=0;
        while(a>0) {
            if(a%2==0) ok=1;
            a/=2;
            x++;
        }
        if(ok) cout<<(1<<x)-1<<"\n";
        else {
            cout<<T[x-1]<<"\n";
        }
    }
    return 0;
}