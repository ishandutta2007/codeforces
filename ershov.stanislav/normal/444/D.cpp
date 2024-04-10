#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

char s[50111];
int len, q;
map<pair<string, string>, int > cache;
map<string, vector<int> > v;
string s1, s2;

int solve() {
    if (cache.count(make_pair(s1, s2))) return cache[make_pair(s1, s2)];
    vector<int> &v1=v[s1];
    vector<int> &v2=v[s2];
    int ans=10000000, len1=(int)s1.length(), len2=(int)s2.length();
    if (v1.size()>v2.size()){
        swap(s1, s2);
        return solve();
    }
    if (v1.size()<100) {
        for (int i=0; i<v1.size(); i++) {
            int j=(int)(lower_bound(v2.begin(), v2.end(), v1[i])-v2.begin());
            if (j<v2.size()) ans=min(ans, max(v1[i]+len1, v2[j]+len2)-v1[i]);
            if (j>0)ans=min(ans, max(v1[i]+len1, v2[j-1]+len2)-v2[j-1]);
        }
    } else {
        int i=0, j=0;
        while (i<v1.size()&&j<v2.size()) {
            ans=min(ans, max(v1[i]+len1, v2[j]+len2)-min(v1[i], v2[j]));\
            if (v1[i]<v2[j]) i++;
            else j++;
        }
    }
    if (ans>1000000) ans=-1;
    cache[make_pair(s1, s2)]=ans;
    cache[make_pair(s2, s1)]=ans;
    return ans;
}

int main() {
    scanf("%s", s);
    len=(int)strlen(s);
    scanf("%d", &q);
    for (int i=0; i<len; i++) {
        string ss="";
        for (int j=i; j<i+4&&j<len; j++) {
            ss+=s[j];
            v[ss].push_back(i);
        }
    }
    for (int i=0; i<q; i++) {
        cin >> s1 >> s2;
        printf("%d\n", solve());
    }
    return 0;
}