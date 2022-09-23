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

string s;
vector < string > v;
long long sum = 0;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    string t = "";
    for(int i = 0; i < s.size(); i++){
        if('a' <= s[i] && s[i] <= 'z'){
            if(t != ""){
                v.pb(t);
                t = "";
            }
        }
        else{
            t += s[i];
        }
    }
    if(t != "")
        v.pb(t);
    for(int i = 0; i < v.size(); i++){
        t = v[i];
        int h = 0;
        long long x = 0;
        for(int j = 0; j < t.size(); j++){
            if(t[j] == '.' && j + 3 == t.size())
                h = 1;
            if(t[j] == '.')
                continue;
            x = x * 10 + t[j] - '0';
        }
        if(h == 0)
            x *= 100;
        sum += x;
    }
    string ans = "";
    int h = 0, h1 = 0;
    if(sum < 10){
        cout << "0.0" << sum << endl;
        return 0;
    }
    if(sum < 100){
        cout << "0." << sum << endl;
        return 0;
    }
    while(sum){
        char c = char(sum % 10 + '0');
        ans += c;
        sum /= 10;
        h++;
        if(h1 == 0 && h == 2){
            h1 = 1;
            h = 0;
            ans += '.';
        }
        else if(h == 3 && sum){
            h = 0;
            ans += '.';
        }
    }
    t = "";
    if(ans[0] == '0' && ans[1] == '0'){
        for(int i = ans.size() - 1; i > 2; i--)
            t += ans[i];
        cout << t << endl;
    }
    else{
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}