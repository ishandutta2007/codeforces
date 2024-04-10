#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,d[1005]={0},s[1005];
    cin >> n >> k;
    for(int i=0;i<n;++i)
        cin >> d[i];
    for(int i=0;i<n;++i) {
        cin >> s[i];
    }
    vector <int> v(1,n);
    bool can[1005]={0};
    while(v.back()) {
        int last=v.back()-1,mx=s[last],r=last;
        while(last>=0) {
            if (s[last]>mx) mx=s[last],r=last;
            --last;
        }
        v.push_back(r);
        can[r]=true;
    }
    reverse(v.begin(),v.end());
    int b=0,ans=0,last=0;
    for(int i=0;i<n;++i) {
        b+=s[i];
        if (can[i]) last=i;
        while(b<d[i]) b+=s[last],ans+=k;
        b-=d[i]; ans+=d[i];
    }
    /*for(int i=1;i<v.size();++i) {
        int tot=(d[v[i]]-d[v[i-1]]);
        b+=s[v[i-1]];
        while(b<tot) b+=s[v[i-1]],ans+=k;
        ans+=tot; b-=tot;
    }*/
    cout << ans << endl;
    return 0;
}