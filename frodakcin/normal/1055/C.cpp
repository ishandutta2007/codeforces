#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

int la, ra, ta;
int lb, rb, tb;

int gcd(int a, int b) {
    if(b > a) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}
int gcd2(int a, int b, int &x, int &y)      //from geeksforgeeks
{ 
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    } 
  
    int x1, y1;
    int gcd = gcd2(b%a, a, x1, y1); 
  
    x = y1 - (b/a) * x1; 
    y = x1;
  
    return gcd; 
} 
ll divF(ll a, ll b) {
    assert(b != 0);
    if(b < 0) a*=-1, b*=-1;
    if(a < 0) return -((-a + b - 1)/b); else return a/b;
}

int ans;
int v1, v2;
void test(ll t) {
    ll a1 = t * ta * v1 + la, a2 = t * ta * v1 + ra + 1;
    ll b1 = t * tb * (-v2) + lb, b2 = t * tb * (-v2) + rb + 1;
    //cerr << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
    ans = (max(ans, static_cast<int>(min(a2, b2) - max(a1, b1))));
}

int main() {
    scanf("%d%d%d%d%d%d", &la, &ra, &ta, &lb, &rb, &tb);
    
    int v = gcd(ta, tb);
    
    gcd2(ta, tb, v1, v2);
    //cerr << (tll(v1) * ta + tll(v2) * tb) << "\n";
    
    if(tll(v1) * ta + tll(v2) * tb == 1) {printf("%d\n", 1 + min(ra-la, rb-lb));return 0;}
    
    ans = 0;
    ll t = divF(lb - la, tll(v1) * ta + tll(v2) * tb);
    test(t - 1);
    test(t);
    test(t + 1);
    
    printf("%d\n", ans);
    
    return 0;
}