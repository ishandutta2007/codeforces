#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, m, cnt;
int ans[N];
vector < int > v;
set < int > s;
char c[N];
int d[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        ans[i] = 1;
    for(int i = 1; i <= m; i++)
        cin >> c[i] >> d[i];
    for(int i = m; i >= 1; i--){
        if(c[i] == '-')
            s.insert(d[i]);
        else
            s.erase(d[i]);
    }
    for(int i = 1; i <= m; i++){
        if(c[i] == '+'){
            if(!s.empty())
                ans[d[i]] = 0;
            if(i > 1){
                if(d[i] != d[i - 1])
                    ans[d[i]] = 0;
            }
            s.insert(d[i]);
        }
        else{
            s.erase(d[i]);
            if(!s.empty())
                ans[d[i]] = 0;
            if(i < m){
                if(d[i + 1] != d[i])
                    ans[d[i]] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        if(ans[i])
            v.pb(i);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " \n"[i == v.size() - 1];
}