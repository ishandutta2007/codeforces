#include <bits/stdc++.h>
using namespace std;

pair<int,int> compute(string &s, int l, int r){
    // cout<<l<<" "<<r<<endl;
    if(l == r){
        if(s[l] == '(')return make_pair(1, 0);
        else return make_pair(0, 1);
    }
    int m = (l+r)/2;
    pair<int,int> y1 = compute(s, l, m);
    pair<int,int> y2 = compute(s, m+1, r);
    int com = min(y1.first, y2.second);
    int nop = y1.first + y2.first - com;
    int noc = y1.second + y2.second - com;
    return make_pair(nop, noc);
}

typedef long long int ll;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    map<int,int> op, cl;
    string s;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin>>s;
        pair<int,int> y = compute(s, 0, s.size()-1);
        if(y.first == 0 && y.second == 0)cnt++;
        else if(y.first == 0)cl[y.second]++;
        else if(y.second == 0)op[y.first]++;
    }
    int ans = cnt/2;
    for(map<int,int>::iterator it = op.begin(); it != op.end(); it++){
        ans += min(it->second, cl[it->first]);
    }
    cout<<ans<<endl;
}