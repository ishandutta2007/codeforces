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

long long n, p;
const int mod = 1000000007;

int main() {
    cin >> n >> p;

    long long sDiv = (n*(n+1)/2) % mod;
    long long sMod = ((p-1)*(p)/2) % mod;

    long long f = ((sDiv * sMod) % mod) * p + sMod * n;

    cout << f % mod;
}