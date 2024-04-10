#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int cnt[200];
char s[510000];
int n;

int main() {
    scanf("%d %s", &n, s);    

    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }

    int odd = 0;
    for (int i = 0; i < 200; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
        }
    }

    int cut_size = -1;
    for (int i = n; i >= 1; i--) if (n % i == 0) {
        if (i % 2 == 0 && odd == 0) {
            cut_size = i;
            break;
        }
        if (i % 2 == 1 && n/i >= odd) {
            cut_size = i;
            break;
        } 
    }

    vector<string> ans;
    int how_many = n/cut_size;
    for (int i = 0; i < how_many; i++) {
        int rem = cut_size;
        string la = "";
        for (int i = 0; i < 200; i++) {
            while (cnt[i] >= 2 && rem >= 2) {
                la += (char)i;
                cnt[i] -= 2;
                rem -= 2;
            }
        }

        string lla = la;
        reverse(all(la));

        if (rem) {
            int found = -1;
            for (int i = 0; i < 200; i++) {
                if (cnt[i] % 2 == 1) {
                    found = i;
                    cnt[i]--;
                    break;
                }
            }

            if (found == -1) {
                for (int i = 0; i < 200; i++) {
                    if (cnt[i]) {
                        found = i;
                        cnt[i]--;
                        break;
                    }
                }
            }

            la += (char)found;
        }

        la += lla;

        ans.push_back(la);
    }

    printf("%d\n", (int)ans.size());
    for (string k : ans) {
        printf("%s ", k.c_str());
    }
}