#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 2005;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E9+9;


int main() {
    int total = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i+1; j < s.length(); j++) {
            for(int k = j+1; k < s.length(); k++) {
                if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') total++;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}