#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

string s;
int c[200];

void solve()
{
        cin >> s;
        for(int i = 0; i < s.size(); i++){
                c[s[i]]++;
        }
        vector < int > v;
        for(int i = 'a'; i <= 'z'; i++){
                if(c[i]){
                        v.push_back(c[i]);
                }
        }
        sort(v.begin(), v.end());
        if(v.size() == 4){
                cout << "Yes" << "\n";
        }
        else if(v.size() == 3 && v.back() > 1){
                cout << "Yes" << "\n";
        }
        else if(v.size() == 2 && v[0] > 1){
                cout << "Yes" << "\n";
        }
        else{
                cout << "No" << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}