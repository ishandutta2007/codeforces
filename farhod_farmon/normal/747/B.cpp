#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int n;
int d[300];
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] != '?')
            d[s[i]]++;
    }
    if(n % 4){
        cout << "===" << endl;
        return 0;
    }
    int need = n / 4;
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            if(d['A'] < need){
                s[i] = 'A';
                d['A']++;
            }
            else if(d['C'] < need){
                s[i] = 'C';
                d['C']++;
            }
            else if(d['G'] < need){
                s[i] = 'G';
                d['G']++;
            }
            else if(d['T'] < need){
                s[i] = 'T';
                d['T']++;
            }
        }
        else if(d[s[i]] > need){
            cout << "===" << endl;
            return 0;
        }
    }
    cout << s << endl;
}