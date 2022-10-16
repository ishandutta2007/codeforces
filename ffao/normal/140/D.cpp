#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

#define INF 1000000000
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define itr iterator
#define sz size()

int N;
int prob[100];
int main() {
    scanf("%d", &N);
    
    REP(i, N) {
        scanf("%d", prob+i);
    }
    
    sort(prob,prob+N);
    int time = 10;
    int pen = 0;
    int sc = 0;
    
    REP(i, N) {
        time += prob[i];
        if (time > 720) break;
        
        sc++;
        pen += max(0, time-360);    
    }
    printf("%d %d\n", sc, pen);
}