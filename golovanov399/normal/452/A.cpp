#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    string a[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    for (int i = 0; i < 8; i++){
        if (s.length() == a[i].length()){
            bool flag = true;
            for (int j = 0; j < s.length(); j++){
                if (s[j] != '.' && s[j] != a[i][j]) flag = false;
            }
            if (flag) k = i;
        }
    }
    cout << a[k] << "\n";

    return 0;
}