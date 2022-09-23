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
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int i = n - 1;
    int cnt = 0;
    while(i >= 0){
        if(s[i] == '<')
            break;
        cnt++;
        i--;
    }
    int j = 0;
    while(j <= i){
        if(s[j] == '>')
            break;
        j++;
        cnt++;
    }
    cout << cnt << endl;
}