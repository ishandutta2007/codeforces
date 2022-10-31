#include <random>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>
#include<queue>
#include<ctime>
#include<unordered_map>

using namespace std;


using ll = long long;
using ull = unsigned long long;

using ld = long double;

const int mod = 998244353;
//const int mod = 1e9 + 7;

int sum(int a, int b)
{
    int c = a + b;
    if (c >= mod)
    {
        c -= mod;
    }
    return c;
}

int dif(int a, int b)
{
    int c = a - b;
    if (c < 0)
    {
        c += mod;
    }
    return c;
}

int mlt(int a, int b)
{
    ll c = a * 1LL * b;
    return c % mod;
}

int ibit(int n, int i)
{
    return ((n >> i) & 1);
}


void outp2(vector<vector<int>> &ou, string s = " ")
{
    cerr << s << endl;
    for (int i = 0; i < ou.size(); i++)
    {
        for (int j = 0; j < ou[i].size(); j++)
        {
            cerr << ou[i][j] << ' ';
        }
        cerr << '\n';
    }
}

int bp(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    int a = 0;
    if (!(y % 2))
    {
        a = bp(x, y / 2);
    }
    return (y % 2) ? mlt(bp(x, y - 1), x) : mlt(a, a);
}

int obr(int x)
{
    return bp(x, mod - 2);
}

const int maxn = 2e5 + 2;
int fact[maxn], ofact[maxn];

void prec()
{
    fact[0] = 1;
    ofact[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fact[i] = mlt(fact[i - 1], i);
    }
    //cerr << "sdsds" << endl;
    ofact[maxn - 1] = obr(fact[maxn - 1]);
    for (int i = maxn - 2; i > 0; i--)
    {
        ofact[i] = mlt(ofact[i + 1], i + 1);
    }
}

int c(int a, int b)
{
    return ((a <= b) && (a >= 0)) ? mlt(fact[b], mlt(ofact[a], ofact[b - a])) : 0;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int tests;
    cin>>tests;
    for(int test=0; test<tests; test++)
    {
        int n;
        cin>>n;
        vector<string>ans;
        vector<int>ost(3);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<n; j++) {
                if (s[j] != '.')
                    ost[(i + j) % 3]++;
            }
            ans.push_back(s);
        }
        int os=0;
        for(int i=0; i<3; i++)
            if(ost[i]<ost[os])
                os=i;
        for(int i=0; i<n; i++)
        {
            string s=ans[i];
            for(int j=0; j<n; j++) {
                if (s[j] != '.'&&((i+j)%3==os))
                {
                    if(s[j]=='X')
                        s[j]='O';
                    else
                        s[j]='X';
                }
            }
            cout<<s<<'\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto st = clock();

        ifstream fin("../input.txt");
        do
        {
            solve(fin);

            cout << "===" << endl;

            string str;
            while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
        } while (fin);

        cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
    solve();
#endif

    return 0;
}