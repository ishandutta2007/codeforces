#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <string>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define INF (1100000099)
#define INFLL (1100000000000000099ll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

int H, M;
int Ans;

inline int ang(int n) {
    if(n < 10) return n*10;
    return (n/10) + (n%10)*10;
}
bool f(int H, int M) {
    return H == ang(M) && M == ang(H);
}
int main() {
    scanf("%d:%d", &H, &M);
    for(; !f(H, M); Ans++, M++, H += M/60, M %= 60, H %= 24);
    printf("%d\n", Ans);
    return 0;
}