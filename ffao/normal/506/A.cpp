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

int n, d;
int g[30010];
int best[30010][600];

bool valid(int v, int off) {
    int jl = d + off - 300;
    if (jl <= 0) return false;
    if (v + jl > 30000) return false;
    return true;
}

int calc(int v, int off) {
    int &ret = best[v][off];
    
    if (ret == -1) {
        ret = 0;

        if (valid(v, off))
            ret = max(ret, calc(v+d+(off  )-300, off));
        if (valid(v, off-1))
            ret = max(ret, calc(v+d+(off-1)-300, off-1));
        if (valid(v, off+1))
            ret = max(ret, calc(v+d+(off+1)-300, off+1));
    
        ret += g[v];
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &d);
    memset(best,-1,sizeof(best));

    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        g[l]++;
    }

    printf("%d\n", calc(d, 300));
}