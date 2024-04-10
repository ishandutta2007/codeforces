#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll BASE1 = 43ll, MOD1 = 1000000007ll;
ll BASE2 = 37ll, MOD2 = 1000000009ll;
int z1hash1, z1hash2, z2hash1, z2hash2;
int hash1[2005][2005], hash2[2005][2005];

char s[5005],z1[5005],z2[5005];
int n,z1len,z2len;
int ans;
vector<ll> mp[2005];

int main()
{
    scanf("%s%s%s",s,z1,z2);
    n = strlen(s);
    z1len = strlen(z1);
    z2len = strlen(z2);
    for (int i = 0; i < n; ++i) {
        hash1[i][i] = s[i] - 96;
        hash2[i][i] = s[i] - 96;
        for (int j = 1; i + j <= n; ++j) {
            hash1[i][i+j] = (hash1[i][i+j-1] * BASE1 + s[i+j] - 96) % MOD1;
            hash2[i][i+j] = (hash2[i][i+j-1] * BASE2 + s[i+j] - 96) % MOD2;
        }
    }
    z1hash1 = z1hash2 = z1[0] - 96;
    for (int i = 1; i < z1len; ++i) {
        z1hash1 = (z1hash1 * BASE1 + z1[i] - 96) % MOD1;
        z1hash2 = (z1hash2 * BASE2 + z1[i] - 96) % MOD2;
    }
    z2hash1 = z2hash2 = z2[0] - 96;
    for (int i = 1; i < z2len; ++i) {
        z2hash1 = (z2hash1 * BASE1 + z2[i] - 96) % MOD1;
        z2hash2 = (z2hash2 * BASE2 + z2[i] - 96) % MOD2;
    }

    int len = max(z1len, z2len);
    for (int i = 0; i < n; ++i) {
        for (int j = len; i + j <= n; ++j) {
            if (hash1[i][i + z1len - 1] == z1hash1 && hash2[i][i + z1len - 1] == z1hash2 &&
                hash1[i + j - z2len][i + j - 1] == z2hash1 &&
                hash2[i + j - z2len][i + j - 1] == z2hash2) {
                mp[j].push_back((ll(hash1[i][i+j-1]) << 32ll) | ll(hash2[i][i+j-1]));
            }
        }
    }

    for (int i = 0; i < 2005; ++i) {
        sort(mp[i].begin(), mp[i].end());
        for (int j = 1; j < mp[i].size(); ++j) {
            if (mp[i][j] != mp[i][j-1]) ++ans;
        }
        if (mp[i].size())
            ++ans;
    }
    printf("%d",ans);

    return 0;
}