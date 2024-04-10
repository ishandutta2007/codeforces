#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = N * N;

using namespace std;

bitset < Q > d[N];

pair < vector < int >, vector < int > > make(vector < int > a)
{
        int n = a.size();

        for(int i = 0; i <= n; i++){
                d[i].reset();
        }
        d[0][0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
                d[i + 1] = d[i] | (d[i] << a[i]);
                sum += a[i];
        }
        vector < int > A, B;
        if(sum % 2 || !d[n][sum / 2]){
                return make_pair(A, B);
        }
        sum /= 2;
        for(int i = n - 1; i >= 0; i--){
                if(a[i] <= sum && d[i][sum - a[i]]){
                        A.push_back(a[i]);
                        sum -= a[i];
                } else{
                        assert(d[i][sum]);
                        B.push_back(a[i]);
                }
        }
        return make_pair(A, B);
}

void solve()
{
        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        int m;
        cin >> m;
        vector < int > b(m);
        for(int i = 0; i < m; i++){
                cin >> b[i];
        }
        if(n != m){
                cout << "No" << "\n";
                return;
        }
        auto A = make(a);
        auto B = make(b);
        if(A.fi.empty() || B.fi.empty()){
                cout << "No" << "\n";
                return;
        }
        if(A.fi.size() < A.se.size()){
                swap(A.fi, A.se);
        }
        if(B.fi.size() > B.se.size()){
                swap(B.fi, B.se);
        }
        sort(A.fi.begin(), A.fi.end());
        sort(A.se.begin(), A.se.end());
        sort(B.fi.begin(), B.fi.end());
        sort(B.se.begin(), B.se.end());
        reverse(B.se.begin(), B.se.end());

        for(auto x: A.se){
                A.fi.push_back(-x);
        }
        for(auto x: B.se){
                B.fi.push_back(-x);
        }


        cout << "Yes" << "\n";
        int x = 0, y = 0;
        for(int i = 0; i < n + m; i++){
                if(i % 2 == 0){
                        y += B.fi[i / 2];
                } else{
                        x += A.fi[i / 2];
                }
                cout << x << " " << y << "\n";
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}