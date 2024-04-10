#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;

int id;
string s;

vector < int > build(int l, int r)
{
        if(l == r){
                return {};
        } else if(l + 1 == r){
                return {l};
        }
        int m = (l + r) / 2;
        auto A = build(l, m);
        auto B = build(m, r);

        if(id == -1){
                return {};
        }

        int i = 0, j = 0;
        vector < int > res;
        while(i < A.size() && j < B.size()){
                if(id == s.size()){
                        id = -1;
                        return {};
                } else if(s[id] == '0'){
                        res.push_back(A[i]);
                        i += 1;
                } else{
                        res.push_back(B[j]);
                        j += 1;
                }
                id += 1;
        }
        while(i < A.size()){
                res.push_back(A[i++]);
        }
        while(j < B.size()){
                res.push_back(B[j++]);
        }
        return res;
}

int solve(int n)
{
        id = 0;
        auto a = build(0, n);
        if(id != s.size()){
                if(id == -1){
                        return 1;
                }
                return 2;
        }
        vector < int > res(n);
        for(int i = 0; i < n; i++){
                res[a[i]] = i + 1;
        }
        cout << n << "\n";
        for(int x: res){
                cout << x << ' ';
        }
        exit(0);
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> s;

        int l = 0, r = 1e5;
        while(l < r){
                int m = (l + r) / 2;
                if(solve(m) == 1){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        solve(l);
        assert(0);
}