#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

vector <char> s = {'W','h','a','t',' ','a','r','e',' ','y','o','u',' ','d','o','i','n','g',' ','a','t',' ','t','h','e',' ','e','n','d',' ','o','f',' ','t','h','e',' ','w','o','r','l','d','?',' ','A','r','e',' ','y','o','u',' ','b','u','s','y','?',' ','W','i','l','l',' ','y','o','u',' ','s','a','v','e',' ','u','s','?',};
vector <char> pref = {'W','h','a','t',' ','a','r','e',' ','y','o','u',' ','d','o','i','n','g',' ','w','h','i','l','e',' ','s','e','n','d','i','n','g',' ','"',};
vector <char> mid = {'"','?',' ','A','r','e',' ','y','o','u',' ','b','u','s','y','?',' ','W','i','l','l',' ','y','o','u',' ','s','e','n','d',' ','"',};
vector <char> post = {'"','?',};

const int BIGMOD = 5e18 + 7;
int len[MAXN];

char get(int num, int k){
    if (num == 0){
        if (k <= s.size()){
            return s[k - 1];
        }
        else{
            return '.';
        }
    }

    if (k <= pref.size()) return pref[k - 1];
    k -= pref.size();
    if (k <= len[num - 1]) return get(num - 1, k);
    k -= len[num - 1];
    if (k <= mid.size()) return mid[k - 1];
    k -= mid.size();
    if (k <= len[num - 1]) return get(num - 1, k);
    k -= len[num - 1];
    if (k <= post.size()) return post[k - 1];
    return '.';
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);

    len[0] = 75;
    for (int i = 1; i <= 54; ++i){
        len[i] = len[i - 1] * 2 + 68;
    }
    for (int i = 55; i < MAXN; ++i){
        len[i] = BIGMOD;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i){
        int num, k;
        cin >> num >> k;
        cout << get(num, k);
    }

    return 0;
}