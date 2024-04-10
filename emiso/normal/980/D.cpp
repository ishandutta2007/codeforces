#include <bits/stdc++.h>
#define MN 10010

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

vector<bool> isp(MN, 1);
vector<int> primos;

void crivo() {
    for(int i = 2; i < MN; i++) {
        if(isp[i]) {
            primos.push_back(i);
            for(int j = 2 * i; j < MN; j += i)
                isp[j] = 0;
        }
    }
}

int transf(int x) {
    if(x == 0) return 0;
    for(int p : primos)
        while(x % (p*p) == 0) x /= (p*p);
    return x;
}

int Mabs(int x) {
    return (x < 0) ? -x : x;
}

int n, ans, a[5005], resp[5005];
vector<bool> ins[2];

int main() {
    crivo();
    scanf("%d", &n);

    ins[0].resize(100000001);
    ins[1].resize(100000001);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] = transf(a[i]);
    }

    for(int i = 0; i < n; i++) {
        int co = 0;
        for(int j = i; j < n; j++) {
            if(a[j] && !ins[a[j]<0][Mabs(a[j])]) co++;
            ins[a[j]<0][Mabs(a[j])] = 1;
            resp[co]++;
            if(co == 0) resp[1]++;
        }
        for(int j = i; j < n; j++) {
            ins[a[j]<0][Mabs(a[j])] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", resp[i]);
    }

    return 0;
}