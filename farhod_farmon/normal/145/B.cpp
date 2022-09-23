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

int a1, a2, a3, a4;
int b1, b2, b3, b4;

string solve(string s, int na1, int na2)
{
    string t = "";
    int f1 = 0, f2 = s.size() - 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '4'){
            f1 = i;
            break;
        }
    }
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '7'){
            f2 = i;
            break;
        }
    }
    for(int i = 0; i < s.size(); i++){
        t += s[i];
        if(i == f1){
            for(int j = 0; j < na1; j++)
                t += '4';
        }
        if(i == f2){
            for(int j = 0; j < na2; j++)
                t += '7';
        }
    }
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '4')
            a1--;
        if(t[i] == '7')
            a2--;
        if(i + 1 < t.size() && t[i] == '4' && t[i + 1] == '7')
            a3--;
        if(i + 1 < t.size() && t[i] == '7' && t[i + 1] == '4')
            a4--;
    }
    if(a1 || a2 || a3 || a4)
        return "-1";
    else
        return t;
}

string s, t, aa1, aa2;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a1 >> a2 >> a3 >> a4;
    b1 = a1;
    b2 = a2;
    b3 = a3;
    b4 = a4;
    aa1 = aa2 = "-1";
    int na1 = a1, na2 = a2;
    for(int i = 0; i <= a3 + a4; i++){
        if(i % 2){
            s += '7';
            na2--;
        }
        else{
            s += '4';
            na1--;
        }
    }
    if(na1 >= 0 && na2 >= 0)
        aa1 = solve(s, na1, na2);
    a1 = b1;
    a2 = b2;
    a3 = b3;
    a4 = b4;
    na1 = a1;
    na2 = a2;
    s = "";
    for(int i = 0; i <= a3 + a4; i++){
        if(i % 2){
            s += '4';
            na1--;
        }
        else{
            s += '7';
            na2--;
        }
    }
    if(na1 >= 0 && na2 >= 0)
        aa2 = solve(s, na1, na2);
    if(aa1 == "-1" && aa2 == "-1")
        cout << -1 << endl;
    else if(aa1 != "-1" && aa2 != "-1")
        cout << min(aa1, aa2) << endl;
    else if(aa1 == "-1")
        cout << aa2 << endl;
    else
        cout << aa1 << endl;
}