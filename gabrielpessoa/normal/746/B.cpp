#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string resposta = "";
    if(n % 2) {
        resposta = resposta + s[0];
        //cout << resposta << endl;
    }
    for(int i = 0; i < n/2; i++) {
        resposta = s[i*2+n%2] + resposta + s[i*2+1+n%2];
        //cout << resposta << endl;
    }
    cout << resposta;
    return 0;
}