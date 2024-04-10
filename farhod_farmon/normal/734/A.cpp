#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n;
int s;
string c;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("three.in");
    //fout("three.out");
    ios_base::sync_with_stdio(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        if(c[i] == 'A')
            s++;
        else
            s--;
    }
    if(s > 0)
        cout << "Anton" << endl;
    else if(s < 0)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}