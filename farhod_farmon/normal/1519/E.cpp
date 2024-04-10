#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 400400;

int G;
map < pair < long long, long long >, int > id;

int get(long long a, long long b, long long c, long long d)
{
        a *= d;
        b *= c;
        long long g = __gcd(a, b);
        a /= g;
        b /= g;
        if(id.find({a, b}) == id.end()){
                id[{a, b}] = ++G;
        }
        return id[{a, b}];
}

int n;
int a[N], b[N];
bool used[N], bot[N], dudu[N];
vector < int > v[N];
vector < vector < int > > res;

void dfs(int x, int p = -1)
{
        used[x] = true;
        vector < int > rem;
        for(int i: v[x]){
                if(i == p || dudu[i]){
                        continue;
                }
                dudu[i] = true;
                int y = a[i] ^ b[i] ^ x;

                if(used[y]){
                        rem.push_back(i);
                } else{
                        dfs(y, i);
                        if(bot[y]){
                                rem.push_back(i);
                        }
                }
        }
        for(int i = 1; i < rem.size(); i += 2){
                res.push_back({rem[i], rem[i - 1]});
        }
        if(rem.size() & 1){
                if(p != -1){
                        res.push_back({rem.back(), p});
                }
        } else{
                bot[x] = true;
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int A, B, C, D;
                cin >> A >> B >> C >> D;

                a[i] = get(A + B, B, C, D);
                b[i] = get(A, B, C + D, D);

                v[a[i]].push_back(i);
                v[b[i]].push_back(i);
        }

        for(int i = 1; i <= G; i++){
                if(!used[i]){
                        dfs(i);
                }
        }

        cout << res.size() << "\n";
        for(auto p: res){
                cout << p[0] << " " << p[1] << "\n";
        }
}