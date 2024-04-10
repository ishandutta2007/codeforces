#include <bits/stdc++.h>

#define lli long long int
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

int n, s1, s2;

int main()
{
    //fin("numbers.in");
    //fout("numbers.out");
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(x > y)
            s1++;
        else if(y > x)
            s2++;
    }
    if(s1 > s2)
        cout << "Mishka" << endl;
    else if(s2 > s1)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!^^" << endl;
}