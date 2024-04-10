#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int whr(int k, const string& s){
    int n = s.length();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++){
        p[i] = p[i - 1];
        while (p[i] > 0 && s[p[i]] != s[i])
            p[i] = p[p[i] - 1];
        if (s[i] == s[p[i]])
            p[i]++;
        if (p[i] == k)
            return i - k;
    }
    return -1;
}

int main(){

    string s, t;
    cin >> s >> t;
    int k = 0;
    int ans1 = -1;
    for (int i = 0; i < t.length(); i++){
        if (t[i] == s[k])
            k++;
        if (k == s.length()){
            ans1 = i;
            break;
        }
    }
    if (ans1 == -1){
        cout << "0\n";
        return 0;
    }
    reverse(all(s));
    reverse(all(t));
    k = 0;
    int ans2 = -1;
    for (int i = 0; i < t.length(); i++){
        if (t[i] == s[k])
            k++;
        if (k == s.length()){
            ans2 = i;
            break;
        }
    }
    if (ans1 + ans2 + 1 > t.length())
        cout << "0\n";
    else
        cout << t.length() - ans1 - ans2 - 1 << "\n";

    return 0;
}