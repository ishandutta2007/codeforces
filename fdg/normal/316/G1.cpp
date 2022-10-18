#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>

using namespace std;

set <string> f;
string p[11]; int l[11],r[11];

bool good(string s,int i) {
    int pos=0,cnt=0;
    while(true) {
        pos=p[i].find(s,pos);
        if (pos==string::npos) break;
        ++cnt; ++pos;
    }
    return cnt>=l[i]&&cnt<=r[i];
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    string s; int n;
    cin >> s >> n;
    for(int i=0;i<n;++i)
        cin >> p[i] >> l[i] >> r[i];
    for(int i=0;i<s.size();++i)
        for(int j=i;j<s.size();++j) {
            bool ok=true;
            string str=s.substr(i,j-i+1);
            for(int t=0;t<n;++t)
                if (!good(str,t)) {
                    ok=false;
                    break;
                }
            if (ok) f.insert(s.substr(i,j-i+1));
        }
    cout << f.size() << endl;
    return 0;
}