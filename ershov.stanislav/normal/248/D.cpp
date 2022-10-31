#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;
int n, t, c, d[555555], res=0, ll=-1;

bool try_ans(int k) {
    if (d[n-1]>k) return false;
    int last=0, now=0, res, l2=-1;
    vector<pair<int, int> > aa;
    for (int i=0; i<n; i++) {
        if (d[i]>k) {
            l2=i;
            if (!last) aa.push_back(make_pair(i, now));
            last=1;
            now+=2;
        } else if (last==1) last=2, l2=i;
        else last=0;
    }
    if (ll>l2) l2=ll;
    res=now+l2+1;
    for (int i=aa.size()-1; i>=0; i--)
        if (2*l2+1-aa[i].first+aa[i].second<res)
            res=2*l2+1-aa[i].first+aa[i].second;
    return res<=t;
}

int ans(int max, int min) {
    if (max==min) return min;
    int mid=(max+min)/2;
    bool a=try_ans(mid);
    if (a) return ans(mid, min);
    else return ans(max, mid+1);
}

int main()
{
    cin >> n >> t;
    string str;
    cin >> str;
    int now = 0;
    for (int i=0; i<n; i++) {
        c=str[i];
        if (c=='H')now++, ll=i;
        if (c=='S')now--;
        d[i]=now;
        if (now>res)res=now;
    }
    if (ll+1>t) cout << -1;
    else {
        cout << ans(res, 0);
    }
    return 0;
}