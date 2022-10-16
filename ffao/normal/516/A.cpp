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
int fact[10];
char c;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        for (int p = 2; p <= (c-'0'); p++) fact[p]++;
    }

    for (int i = 9; i >= 2; i--) {
        for (int j = 9; j > i; j--) {
            if (j % i == 0) {
                fact[i] += fact[j];
                fact[j/i] += fact[j];
                fact[j] = 0;
            }
        }
    }


    for (int i = 0; i < fact[7]; i++) {
        printf("7");
        fact[5]--;
        fact[3] -= 2;
        fact[2] -= 4;
    }

    for (int i = 0; i < fact[5]; i++) {
        printf("5");
        fact[3] -= 1;
        fact[2] -= 3;
    }

    for (int i = 0; i < fact[3]; i++) {
        printf("3");
        fact[2]--;
    }

    for (int i = 0; i < fact[2]; i++) {
        printf("2");
    }
    printf("\n");
}