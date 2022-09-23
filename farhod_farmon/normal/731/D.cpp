#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000500;

using namespace std;

int n, c;
int d[N];

void doit(int x, int y)
{
    if(x < y){
        d[0]++;
        d[c - y + 1]--;
        d[c - x + 1]++;
        d[c + 1]--;
        return;;
    }
    d[c - x + 1]++;
    d[c - y + 1]--;
    return;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> c;
    vector < int > last;
    for(int i = 1; i <= n; i++){
        int l;
        cin >> l;
        vector < int > v(l);
        int start = -1;
        for(int j = 0; j < l; j++){
            cin >> v[j];
            if(j < (int)last.size() && last[j] != v[j] && start == -1)
                start = j;
        }
        if(start == -1){
            if(i == 1){
                d[0]++;
                last = v;
                continue;
            }
            if(last.size() > v.size()){
                cout << -1 << endl;
                return 0;
            }
            else{
                last = v;
                d[0]++;
                continue;
            }
        }
        doit(last[start], v[start]);
        last = v;
    }
    for(int i = 0; i < c; i++){
        if(d[i] == n){
            cout << i << endl;
            return 0;
        }
        d[i + 1] += d[i];
    }
    cout << -1 << endl;
}