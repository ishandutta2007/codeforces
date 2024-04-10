#include<bits/stdc++.h>
using namespace std;
#define int long long

int ANS_T, ANS_C;

int T, C;

const int N = 2007;
const int CHEL = 10;

int pos[N];
int to[N];

int gr[CHEL];

void print(vector <int> a) {
    cout << "next ";
    for (int e : a) cout << e << ' ';
    cout << '\n';
    #ifdef HOME
    for (int e : a) pos[e] = to[pos[e]];        
    for (int i = 0; i < CHEL; ++i) gr[i] = pos[i];

    for (int i = 0; i < CHEL; ++i) cout << gr[i] << ' ';
    cout << '\n';
    #else
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            gr[c - '0'] = i;
        }   
    }       
    #endif
}   
void init() {
    ANS_T = 3;
    ANS_C = 3;
    for (int i = 0; i < ANS_T + ANS_C - 2; ++i) {
        to[i] = i + 1;
    }   
    to[ANS_T + ANS_C - 2] = ANS_T - 1;
}   
signed main() {
    #ifdef HOME
    init();
    #endif
    int K = 0;
    while (1) {
        print({0, 1});
        print({0});
        ++K;
        if (gr[0] == gr[1]) break;
    }   

    #ifdef HOME
    cout << "K = " << K << '\n';
    #endif

    vector <int> v;
    for (int i = 0; i < CHEL; ++i) v.push_back(i);
    while (1) {
        print(v);
        if (gr[0] == gr[CHEL - 1]) break;
    }   
    cout << "done\n";
    
    // T - edges
    // C - cycle
    // K = T + X
    // K mod C = 0
    // T + X mod C = 0
    // -X mod C = T
}