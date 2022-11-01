#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int appr[100007 * 8];

void build(int left, int right, int p)
{
    appr[p] = 0x7f7f7f7f;
    int mid = (left + right) >> 1;
    if (left < right)
    {
        build(left, mid, p*2);
        build(mid+1, right, p*2+1);
    }
}

void push_up(int p)
{
    appr[p] = min(appr[p*2], appr[p*2+1]);
}

void add(int left, int right, int x, int p, int y)
{
   // cout << "x = " << x << endl;
   // while(1);
    if (left == right)
    {
        appr[p] = min(appr[p], y);
        return;
    }
    int mid = (left + right) >> 1;
    if (x <= mid) add(left, mid, x, p*2, y);
    else add(mid+1, right, x, p*2+1, y);
    push_up(p);
}

int invmin(int left, int right, int l, int r, int p)
{
    //cout << "l = " << l << " r = " << r << endl;
    if (r < l) return 0x7f7f7f7f;
    if (l <= left && r >= right)
        return appr[p];
    int mid = (left + right) >> 1, ret = 0x7f7f7f7f;
    if (l <= mid) ret = invmin(left, mid, l, r, p*2);
    if (r > mid) ret = min(ret, invmin(mid+1, right, l, r, p*2+1));
    return ret;
}

vector<long long> X;
int n, g, r;
vector<int> co;

int RIGHT(int x)
{
    int l = 0, r = co.size()-1;
    while (l < r)
    {
        int mid = ((l + r) >> 1)+1;
        if (co[mid] <= x)
            l = mid;
        else r = mid-1;
    }
    if (co[l] > x) --l;

    return l + 1;
}

int LEFT(int x)
{
    int l = 0, r = co.size()-1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (co[mid] >= x)
            r = mid;
        else l = mid+1;
    }
    if (co[l] < x) ++l;
    return l + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> g >> r;
    vector<int> le;
    le.resize(n+1);
    REP(i, n+1) cin >> le[i];
    ++n;
    X.resize(n+1);
    X[0] = 0;
    REP(i, n) X[i+1] = X[i]+le[i];

    vector<long long> dp;
    dp.resize(n);
    dp[n-1] = X[n]-X[n-1];
    for (int i = 1; i < n; ++i)
        co.push_back(X[i]%(r+g));
    sort(co.begin(), co.end());
    co.erase(unique(co.begin(), co.end()), co.end());
    //REP(i, co.size()) rev[co[i]] = i;
    build(0, n+1, 1);
 //   cout << LEFT(X[n-1]%(r+g)); while(1);
 //cout << "tmp = " << X[n-1]%(r+g) << endl;
    add(0, n+1, LEFT(X[n-1]%(r+g)), 1, n-1);
  //  cout << "co:\n";
  //  REP(i, co.size()) cout << co[i] << " ";
  //  cout << endl;
    for (int i = n-2; i >= 0; --i)
    {
        long long cnt = X[i]%(r+g);
//        cnt = (r+g-cnt)%r+g;
        //g<=(xj-xi)%p < r+g
        long long left = cnt+g, right = r+g-1+cnt, first;
      //  cout << "left = " << left << " right = " << right << endl;
        left %= r+g;
        right %= r+g;
        if (left <= right)
        {
            //left to right
            int L = LEFT(left), R = RIGHT(right);
            first = invmin(0, n+1, L, R, 1);
        }
        else
        {
            //0 to left, right to r+g-1
            int L = LEFT(0), R = RIGHT(right);
            first = invmin(0, n+1, L, R, 1);
            L = LEFT(left), R = RIGHT(r+g-1);
            first = min((int)first, (int)invmin(0, n+1, L, R, 1));
        }

     //   cout << "first = " << first << endl;

        if (first == 0x7f7f7f7f)
            dp[i] = X[n]-X[i];
        else
        {
            dp[i] = dp[first]+X[first]-X[i];
            int cnt = (X[first]-X[i])%(r+g);
     //       cout << "cnt = " << cnt << " " << "X[first] = " << X[first] << endl;
         //   assert(cnt >= g && cnt < r+g);
            cnt = r+g - cnt;
      //      cout << "X[first]-X[i]=" << X[first]-X[i] << " cnt = " << cnt << endl;
            dp[i] += cnt;
        }
        if (i) add(0, n+1, LEFT(X[i]%(r+g)), 1, i);
    }
   // for (int i = 0; i < n; ++i)
   //     cout << dp[i] << " ";
   // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int cnt;
        cin >> cnt;
       // --cnt;
        long long cnt1=cnt;
        cnt %= r+g;
        cnt = r+g-cnt;
        cnt %= r+g;
        //g<=(xj-x0+t0)%p < r+g
        long long left = cnt+g, right = r+g-1+cnt, first;
        left %= r+g;
        right %= r+g;
       // cout << "left = " << left << " right = " << right << endl;
        long long ans;
        if (left <= right)
        {
            //left to right
            int L = LEFT(left), R = RIGHT(right);
      //      cout << "L = " << L << " R = " << R << endl;
            first = invmin(0, n+1, L, R, 1);
        }
        else
        {
            //0 to left, right to r+g-1
            int L = LEFT(0), R = RIGHT(right);
            first = invmin(0, n+1, L, R, 1);
            L = LEFT(left), R = RIGHT(r+g-1);
            first = min((int)first, (int)invmin(0, n+1, L, R, 1));
        }
      //  cout << "first = " << first << endl;
        if (first == 0x7f7f7f7f)
            ans = X[n]-X[0];
        else
        {
            ans = dp[first]+X[first];
            int cnt = ((long long)cnt1 + X[first])%(r+g);
       //     cout << "cnt = " << cnt << endl;
            cnt = r+g - cnt;
            ans += cnt;
        }
        cout << ans+cnt1 << endl;
    }
    return 0;
}