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

long long arr[110000];
long long score[110000];
int n;
long long j;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &j);
        arr[j]++;
    }   

    score[1] = arr[1];
    for (int i = 2; i <= 100010; i++) {
        score[i] = max(score[i-1], score[i-2] + i * arr[i]); 
    }

    printf("%I64d\n", score[100010]);
}