#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

int n;
string s;
vector < int > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W')
            continue;
        int j = i;
        while(j < n && s[j] == 'B')
            j++;
        v.pb(j - i);
        i = j - 1;
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}