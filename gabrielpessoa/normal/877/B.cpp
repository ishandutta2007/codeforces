#include <bits/stdc++.h>
using namespace std;

#define SIZE 5005
#define INF 0x3f3f3f

int prefixA[SIZE];
int prefixB[SIZE];

int main() {
    int best = 0;
    string s;
    cin >> s;
    for(int i = 1; i <= s.length(); i++) {
        prefixA[i] = prefixA[i-1];
        prefixB[i] = prefixB[i-1];
        if(s[i-1]=='a') {
            prefixA[i]++;
        } else {
            prefixB[i]++;
        }
    }
    for(int i = 0; i <= s.length(); i++) {
        for(int j = i; j <= s.length(); j++) {
            int soma = prefixA[i] + prefixB[j] - prefixB[i] + prefixA[s.length()] - prefixA[j];
            best = max(best, soma);
        }
    }
    cout << best << endl;
    return 0;
}