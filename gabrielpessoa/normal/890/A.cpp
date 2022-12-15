#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 1E5+5;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll fact = 1E9+7;

int palavra[SIZE];
int pos[30];
string s[SIZE];

bool conc(int a, int b) {
    char inicial = s[b][0];
    int pos = -1;
    for(int i = 0; i < s[a].length(); i++) {
        if(s[a][i] == s[b][0]) {
            pos = i;
            break;
        }
    }
    if(pos == -1) {
        return false;
    }
    for(int i = 0; i < s[b].length(); i++) {
        if(pos+i >= s[a].length()) {
            s[a] += s[b][i];
        } else if(s[a][pos+i] != s[b][i]) {
            return false;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(palavra[i] == b) {
            palavra[i] = a;
        }
    }
    s[b] = "";
    return true;
}

int main() {
    int arr[6];
    int sum = 0;
    for(int i = 0; i < 6; i++) {
        scanf("%d", arr+i);
        sum += arr[i];
    }
    for(int i = 0; i < 6; i++) for(int j = i + 1; j < 6; j++) for(int k = j + 1; k < 6; k++) {
        if(arr[i] + arr[j] + arr[k] == sum - arr[i] - arr[j] - arr[k]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}