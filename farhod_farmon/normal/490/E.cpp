#include <bits/stdc++.h>

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

string get(string x, string y)
{
    if(x.size() > y.size()){
        cout << "NO\n";
        exit(0);
    }
    if(x.size() < y.size()){
        if(y[0] == '?')
            y[0] = '1';
        for(int i = 1; i < y.size(); i++)
            if(y[i] == '?')
                y[i] = '0';
        return y;
    }
    for(int i = 0; i < x.size(); i++){
        if(x[i] > y[i])
            break;
        if(y[i] == '?')
            continue;
        if(y[i] > x[i]){
            for(int j = 0; j < i; j++)
                if(y[j] == '?')
                    y[j] = x[j];
            for(int j = i + 1; j < y.size(); j++)
                if(y[j] == '?')
                    y[j] = '0';
            return y;
        }
    }
    for(int i = x.size() - 1; i >= 0; i--){
        if(y[i] != '?')
            continue;
        if(x[i] == '9')
            continue;
        bool can = true;
        for(int j = 0; j < i; j++){
            if(y[j] == '?')
                continue;
            if(x[j] > y[j])
                can = false;
        }
        if(!can)
            continue;
        for(int j = 0; j < i; j++)
            if(y[j] == '?')
                y[j] = x[j];
        for(int j = i + 1; j < x.size(); j++)
            if(y[j] == '?')
                y[j] = '0';
        y[i] = x[i] + 1;
        return y;
    }
    cout << "NO\n";
    exit(0);
}

int n;
string s[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    s[0] = "";
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] = get(s[i - 1], s[i]);
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << s[i] << "\n";
}