#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define RI(i,n) for(int i = 1, _n = (n); i <= _n; ++i)
const int inf = 1e9 + 5, nax = 5e3 + 5;
const int mod = 1e9 + 7;

int s[nax], t[nax], pom[nax];
int n;

void F() {
    RI(i, n) s[i] = 0;
    RI(i, n) s[i] = (s[i - 1] + t[i]) % mod;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    
    int start, nie, k;
    cin >> n >> start >> nie >> k;
    
    RI(i, n) if(i != nie) t[i] = 1;
    F();
    
    while(k--) {
        RI(a, n) {
            if(a == nie) {
                pom[a] = 0;
                continue;
            }
            int del = abs(a - nie);
            int low = max(1, a - del + 1);
            int high = min(n, a + del - 1);
            pom[a] = s[high] - s[low - 1] - t[a];
            while(pom[a] < 0) pom[a] += mod;
            pom[a] %= mod;
        }
        RI(a, n) t[a] = pom[a];
        F();
    }
    cout << t[start];
    return 0;
}