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

bool l[N], r[N];
set < pair < int, int > > s;
int n, x, i, j, h;

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    s.insert({x, 1});
    for(i = 2; i <= n; i++){
        cin >> x;
        auto a = s.lower_bound({x, -1});
        if(a == s.end())
            a--;
        if(x > a->fi){
            if(!r[a->se]){
                r[a->se] = true;
                cout << a->fi << " ";
            }
            else{
                a++;
                l[a->se] = true;
                cout << a->fi << " ";
            }
        }
        else{
            if(!l[a->se]){
                l[a->se] = true;
                cout << a->fi << " ";
            }
            else{
                a--;
                r[a->se] = true;
                cout << a->fi << " ";
            }
        }
        s.insert({x, i});
    }
}