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

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n;

vector<int> d;

int main() {
    scanf("%d", &n);

    while (n) {
        d.push_back(n%10);
        n /= 10;
    }

    int t = 0;
    for (int k : d) {
        t = max(t, k);
    }

    printf("%d\n", t);
    for (int i = 0; i < t; i++) {
        bool seen = false;
        for (int j = d.size()-1; j >= 0; j--) {
            if (i < d[j]) {seen = true; printf("1");}
            else if (seen) printf("0");
        }
        printf(" ");
    }
    printf("\n");
}