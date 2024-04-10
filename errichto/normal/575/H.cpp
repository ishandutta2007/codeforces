#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) {}
#endif

/////////////////////////////////////////////////////////


const int Mod = 1000000007;
const int MaxSiz = 2100000;

int N;
int facts[MaxSiz], invFacts[MaxSiz];

int pow_mod(int a, int n){
    int res = 1, coef = 1;
    while(coef < n){
        if(n & coef) res = ((LL)res * a) % Mod;
        a = ((LL)a*a) % Mod;
        coef *= 2;
    }
    return res;
}

int inv_mod(int a){
    return pow_mod(a, Mod-2);
}

void mkfacts(){
    facts[0] = invFacts[0] = 1;
    for(int i = 1; i <= 2*N+5; i++){
        facts[i] = ((LL)facts[i-1] * i) % Mod;
        invFacts[i] = ((LL)invFacts[i-1] * inv_mod(i)) % Mod;
    }
}

void input(){
    scanf("%d", &N);
}

int main(){
    input();
    mkfacts();
    int result = 0;

    for(int k = 1; k <= N+1; k++){
        int coef = facts[N+k];
        coef = ((LL)coef * invFacts[k]) % Mod;
        coef = ((LL)coef * invFacts[N]) % Mod;
        result = (result+coef) % Mod;
    }

    printf("%d\n", result);
}