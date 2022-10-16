#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

string k;

int main() {
    cin >> k;

    for (int i = 0; i < k.size(); i++) {
        for (int j = i+1; j <= k.size(); j++) {
            string pref = k.substr(0, i);
            string suf = k.substr(j);

            if (pref + suf == "CODEFORCES") {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
}