#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, tot = 0;
string pol;

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> pol;

        if(pol == "Tetrahedron") tot += 4;
        else if(pol == "Cube") tot += 6;
        else if(pol == "Octahedron") tot += 8;
        else if(pol == "Dodecahedron") tot += 12;
        else if(pol == "Icosahedron") tot += 20;
    }

    printf("%d\n", tot);
    return 0;
}