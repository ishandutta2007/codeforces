#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <map>

using namespace std;

const int64_t mod1 = (int)1e9 + 7;
const int64_t mod2 = (int)1e9 + 9;
const int mul1 = 257;
const int mul2 = 263;

struct hsh { int64_t v1, v2; hsh(){} hsh(int64_t v1, int64_t v2) : v1(v1 % mod1), v2(v2 % mod2) {} };

bool operator< (const hsh& a, const hsh& b)
{
    return make_pair(a.v1, a.v2) < make_pair(b.v1, b.v2);
}

bool operator== (const hsh& a, const hsh & b)
{
    return a.v1 == b.v1 && a.v2 == b.v2;
}

const int max_pow = (int)2e6;
hsh pows[max_pow];
hsh s_hash[max_pow];

void precompute_pows()
{
    pows[0] = hsh(1, 1);
    for (int i = 1; i < max_pow; i++)
        pows[i] = hsh(pows[i-1].v1 * mul1, pows[i-1].v2 * mul2);
}

void compute_hash(const string& s)
{
    s_hash[0] = hsh(s[0] * pows[0].v1,
                    s[0] * pows[0].v2);
    for (int i = 1; i < s.length(); i++)
        s_hash[i] = hsh(s_hash[i-1].v1 + s[i] * pows[i].v1,
                        s_hash[i-1].v2 + s[i] * pows[i].v2);
}

hsh substr_hash(const string& s)
{
    hsh res = hsh(s[0] * pows[0].v1,
                  s[0] * pows[0].v2);
    for (int i = 1; i < s.length(); i++)
        res = hsh(res.v1 + s[i] * pows[i].v1,
                  res.v2 + s[i] * pows[i].v2);
    return res;
}

#define int int64_t

int gcd(int a, int b, int& x, int& y)
{
	if (a == 0)
    {
		x = 0, y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}

int rev(int a, int m)
{
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1)
    {
        cout << "Bug :(" << endl;
        exit(256);
    }
    else
    {
        x = (x % m + m) % m;
        return x;
    }
}

#undef int

hsh substr_hash(int l, int r)
{
    hsh res;
    if (l == 0)
        return s_hash[r];
    else
    {
        hsh h1 = hsh(mod1 + s_hash[r].v1 - s_hash[l-1].v1,
                     mod2 + s_hash[r].v2 - s_hash[l-1].v2);
        res = hsh(h1.v1 * rev(pows[l].v1, mod1),
                  h1.v2 * rev(pows[l].v2, mod2));
    }
    return res;
}


int n, k, g;
string s;
vector <string> v;
map <hsh, int> mp;

vector <int> ans;
vector <char> used;

inline void push(int num)
{
    ans.push_back(num);
    used[ans.back()] = true;
}

inline void pop()
{
    used[ans.back()] = false;
    ans.pop_back();
}

inline void clean()
{
    while (!ans.empty()) pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    cin >> g;
    v.resize(g);
    for (int i = 0; i < g; i++) cin >> v[i];
    s += s;
    precompute_pows();
    compute_hash(s);
    for (int i = 0; i < g; i++)
        mp[substr_hash(v[i])] = i+1;
    used.assign(g+1, false);
    ans.reserve(n);
    ans.clear();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            hsh shash = substr_hash(i + j*k, i + j*k + k-1);
            if (mp.count(shash))
            {
                int v = mp[shash];
                if (!used[v])
                    push(mp[shash]);
                else
                    break;
            }
            else
                break;
        }
        if (ans.size() == n)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) cout << ans[i] << " ";
            cout << endl;
            return 0;
        }
        clean();
    }
    cout << "NO" << endl;
    return 0;
}