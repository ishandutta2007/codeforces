#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int h[N];
int l[N];
int r[N];

void fail()
{
        cout << "NO" << "\n";
        exit(0);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> l[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> r[i];
        }
        vector < int > v;
        for(int i = 1; i <= n; i++){
                if(l[i] > v.size()){
                        fail();
                }
                vector < int > nv;
                for(int j = 0; j < l[i]; j++){
                        nv.push_back(v[j]);
                }
                nv.push_back(i);
                for(int j = l[i]; j < v.size(); j++){
                        nv.push_back(v[j]);
                }
                v = nv;
        }
        for(int i = 0; i < v.size(); i++){
                h[v[i]] = i;
        }
        v.clear();
        for(int i = n; i >= 1; i--){
                if(r[i] > v.size()){
                        fail();
                }
                vector < int > nv;
                for(int j = 0; j < r[i]; j++){
                        nv.push_back(v[j]);
                }
                nv.push_back(i);
                for(int j = r[i]; j < v.size(); j++){
                        nv.push_back(v[j]);
                }
                v = nv;
        }
        for(int i = v.size() - 1; i >= 0; i--){
                if(i == v.size() - 1){
                        a[v[i]] = 1;
                        continue;
                }
                int x = v[i], y = v[i + 1];
                if(h[x] < h[y]){
                        a[x] = a[y] + 1;
                }
                else{
                        a[x] = a[y];
                }
        }
        for(int i = 1; i <= n; i++){
                int le = 0, re = 0;
                for(int j = 1; j <= n; j++){
                        if(i < j) re += a[j] > a[i];
                        if(i > j) le += a[j] > a[i];
                }
                if(le != l[i] || re != r[i]){
                        fail();
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}