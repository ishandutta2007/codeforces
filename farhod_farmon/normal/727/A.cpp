#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 500500;

using namespace std;

vector < long long > v;
long long a, b;

void rec(long long a)
{
    if(a > b)
        return;
    v.pb(a);
    if(a == b){
        cout << "YES" << endl;
        cout << v.size() << endl;
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        exit(0);
    }
    rec(a * 2);
    rec(a * 10 + 1);
    v.pop_back();
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    rec(a);
    cout << "NO" << endl;
}