#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a, c;
int n, m;

int len[105];

int run(int sc){
    int l = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == c[(sc + l)%m])l++;
    }
    return l;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int b, d;
    cin>>b>>d;
    cin>>a>>c;
    n = a.size();
    m = c.size();

    for(int i = 0; i < m; i++){
        len[i] = run(i);
    }
    ll curpos = 0;
    for(int i = 0; i < b; i++){
        curpos = curpos + len[curpos%m];
    }
    cout<<curpos/(m*d)<<endl;
}