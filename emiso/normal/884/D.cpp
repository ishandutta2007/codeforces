#include <bits/stdc++.h>
#define MN 200020

using namespace std;
typedef long long ll;

int n, a;
ll tot;

multiset<ll> ms;

void rem2() {
    ll x = *(ms.begin());
    ms.erase(ms.begin());

    x += *(ms.begin());
    ms.erase(ms.begin());

    tot += x;
    ms.insert(x);
}

void rem3() {
    ll x = *(ms.begin());
    ms.erase(ms.begin());

    x += *(ms.begin());
    ms.erase(ms.begin());

    x += *(ms.begin());
    ms.erase(ms.begin());

    tot += x;
    ms.insert(x);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        ms.insert(a);
    }

    if(ms.size() % 2 == 0) rem2();

    while(ms.size() > 1) {
        rem3();
    }

    printf("%lld\n", tot);
    return 0;
}