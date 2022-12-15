#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

string ans[1<<8][3];
bool ok[1<<8];
set<pair<int, pair<string,pair<int,int>>>> S;

void compare(string s, pair<int,int> www)
{
    if (ans[www.first][www.second].size() == 0)
    {
        ans[www.first][www.second] = s;
        S.insert(make_pair(ans[www.first][www.second].size(),make_pair(ans[www.first][www.second],www)));
        return;
    }
    if (s.size() > ans[www.first][www.second].size()) return;
    if (s.size() < ans[www.first][www.second].size() || s < ans[www.first][www.second])
    {
        S.erase(make_pair(ans[www.first][www.second].size(),make_pair(ans[www.first][www.second],www)));
        ans[www.first][www.second] = s;
        S.insert(make_pair(ans[www.first][www.second].size(),make_pair(ans[www.first][www.second],www)));
        return;
    }
}

int main()
{
    S.insert(make_pair(1,make_pair("x",make_pair(16+32+64+128,0))));
    ans[16+32+64+128][0] = "x";
    S.insert(make_pair(1,make_pair("y",make_pair(4+8+64+128,0))));
    ans[ 4+8+64+128][0] = "y";
    S.insert(make_pair(1,make_pair("z",make_pair(2+8+32+128,0))));
    ans [2+8+32+128][0] = "z";
    int t = 0;
    while (S.size())
    {
        pair<string,pair<int,int>> q = S.begin()->second;
        S.erase(S.begin());
        
        if (q.second.second == 0)
            compare("!"+q.first,make_pair(q.second.first^255,0));
        if (q.second.second == 0)
            compare(q.first,make_pair(q.second.first,1));
        if (q.second.second == 1)
            compare(q.first,make_pair(q.second.first,2));
        if (q.second.second == 2)
            compare("("+q.first+")",make_pair(q.second.first,0));
        if (q.second.second == 1)
            FOR (i,0,1<<8)
            if (ans[i][0].size())
                compare(ans[i][0]+"&"+q.first, make_pair(i&q.second.first,1)),
                compare(q.first+"&"+ans[i][0], make_pair(i&q.second.first,1));
        if (q.second.second == 2)
            FOR (i,0,1<<8)
            if (ans[i][1].size())
                compare(ans[i][1]+"|"+q.first, make_pair(i|q.second.first,2)),
                compare(q.first+"|"+ans[i][1], make_pair(i|q.second.first,2));
    }
    //cout << t << endl;
    FOR (i,0,256)
    {
        compare(ans[i][1],make_pair(i,0));
        compare(ans[i][2],make_pair(i,0));
        //cout << i<<" -> "<<ans[i][0] << endl;
    }
    int n;
    cin >> n;
    FOR (i,0,n)
    {
        string ss; int e = 0;
        cin >> ss;
        reverse(ss.begin(),ss.end());
        FOR (z,0,8) e = 2*e+ss[z]-'0';
        cout << ans[e][0] << endl;
    }
}