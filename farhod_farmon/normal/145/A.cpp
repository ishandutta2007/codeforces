#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

int x, y;
string a, b;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            if(a[i] == '4')
                x++;
            else
                y++;
        }
    }
    cout << max(x, y) << endl;
}