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
 
char sttt[60];
string s[51000];

int n,l,x,y;

bool comp(string a, string b) {
    return (a+b)<(b+a);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", sttt);
        s[i] = sttt;
    }    

    sort(s, s+n, comp);

    for (int i = 0; i < n; i++) {
        printf("%s", s[i].c_str());
    }
    printf("\n");
}