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

const int N = 110;

using namespace std;

int n;
char letter;
string s;
bool used[N];
int ch[N];
map < string, bool > hsh;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string t;
        cin >> t;
        for(int j = 0; j < t.size(); j++)
            if('A' <= t[j] && t[j] <= 'Z')
                t[j] = t[j] - 'A' + 'a';
        hsh[t] = true;
    }
    cin >> s >> letter;
    for(int i = 0; i < s.size(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
            used[i] = true;
        }
    }
    for(int i = 0; i < s.size(); i++){
        string t = "";
        for(int j = i; j < s.size(); j++){
            t += s[j];
            if(hsh.find(t) != hsh.end()){
                ch[i]++;
                ch[j + 1]--;
            }
        }
    }
    for(int i = 0; i < s.size(); i++){
        ch[i + 1] += ch[i];
        if(ch[i]){
            if(s[i] == letter){
                if(letter == 'a')
                    s[i] = 'b';
                else
                    s[i] = 'a';
            }
            else
                s[i] = letter;
        }
        if(used[i])
            s[i] = s[i] - 'a' + 'A';
    }
    cout << s << endl;
}