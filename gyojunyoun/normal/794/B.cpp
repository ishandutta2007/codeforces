#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define upmin(ans,ansx) (ans)=min((ans),(ansx))
#define upmax(ans,ansx) (ans)=max((ans),(ansx))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

ld A;
int N, H;

int main() {
    scanf("%d%d", &N, &H);
    for(int i = 1; i < N; i++) {
        ld x = sqrt((ld)H*(ld)H*(ld)i/(ld)N);
        printf("%.20lf ", x);
    }
    return 0;
}