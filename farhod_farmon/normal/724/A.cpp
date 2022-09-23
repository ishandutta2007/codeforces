#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

map < string, int > ss;
int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    ss["monday"] = 0;
    ss["tuesday"] = 1;
    ss["wednesday"] = 2;
    ss["thursday"] = 3;
    ss["friday"] = 4;
    ss["saturday"] = 5;
    ss["sunday"] = 6;
    int x = ss[a],
        y = ss[b];
    for(int i = 0; i < 12; i++){
        if((x + d[i]) % 7 == y){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}