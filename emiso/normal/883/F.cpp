#include <bits/stdc++.h>

using namespace std;

int n;
string s;
set < string > aux;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        string ns = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'u') ns += "oo";
            else if (s[j] == 'h') {
                while (!ns.empty() && ns.back() == 'k') ns.pop_back();
                ns += s[j];
            }
            else ns += s[j];
        }
        aux.insert(ns);
    }
    printf("%d\n", aux.size());
    return 0;
}