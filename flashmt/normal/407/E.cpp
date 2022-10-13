#include <bits/stdc++.h>
using namespace std;

int n, k, d, a[200200], bound[200200], rem[200200];
map <int,int> lastId;

struct SegmentTree 
{
    int low, mid, high, value, addedValue;
    // value = (max - min) - length
    SegmentTree *left, *right;
    
    SegmentTree(int low, int high) 
    {
        this -> low = low;
        this -> high = high;
        mid = (low + high) / 2;
        value = 0;
        addedValue = 0;
        
        if (low != high)
        {
            left = new SegmentTree(low, mid);
            right = new SegmentTree(mid + 1, high);
        }       
    }
    
    void updateNode(int v)
    {
        addedValue += v;
        value += v;
    }
    
    void update(int x, int y, int v)
    {
        if (x == low && y == high) 
        {
            updateNode(v);
            return;
        }
        
        if (addedValue)
        {
            left -> updateNode(addedValue);
            right -> updateNode(addedValue);
            addedValue = 0;
        }
        
        if (x <= mid) left -> update(x, min(y, mid), v);
        if (mid < y) right -> update(max(x, mid + 1), y, v);
        
        value = min(left -> value, right -> value) + addedValue;
    }
    
    int find(int x, int y, int k)
    {
        if (value > k) return 0;
        if (low == high) return low;
        
        if (addedValue)
        {
            left -> updateNode(addedValue);
            right -> updateNode(addedValue);
            addedValue = 0;
        }
        
        if (low == x && high == y)
        {
            if (left -> value <= k) return left -> find(low, mid, k);
            return right -> find(mid + 1, high, k);
        }
        
        if (x <= mid)
        {
            int res = left -> find(x, min(y, mid), k);
            if (res) return res;
        }
        
        if (mid < y)
        {
            int res = right -> find(max(x, mid + 1), y, k);
            if (res) return res;
        }
        
        return 0;
    }
};

void solve0()
{
    int ans = 0, posAns = 0;
    for (int i = 1, curLen = 1; i <= n; i++)
    {
        if (i > 1 && a[i] == a[i - 1]) curLen++;
        else curLen = 1;
        if (curLen > ans) ans = curLen, posAns = i;
    }
    
    cout << posAns - ans + 1 << ' ' << posAns << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    //freopen("e.in", "r", stdin);
    
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        if (d)
        {
            rem[i] = a[i] % d;
            a[i] /= d;
            if (rem[i] < 0) a[i]--, rem[i] += d;
        }
    }
    
    // special
    if (!d) 
    {
        solve0();
        return 0;
    }
    
    // calc bound
    for (int i = 1; i <= n; i++)
    {
        if (lastId.count(a[i])) bound[i] = lastId[a[i]];
        lastId[a[i]] = i;
    }
    
    // solve
    int ans = 0, posAns = 1;
    SegmentTree tree(1, n);
    vector <int> stackMin, stackMax, posMin, posMax;
    stackMin.push_back(a[1]); posMin.push_back(1);
    stackMax.push_back(a[1]); posMax.push_back(1);
    
    for (int i = 2, from = 1; i <= n; i++)
    {
        from = max(from, bound[i] + 1);
        while (rem[from] != rem[i]) from++;
        
        int lastPos = i;
        while (!stackMax.empty() && stackMax.back() < a[i])
        {
            tree.update(posMax.back(), lastPos - 1, a[i] - stackMax.back());
            lastPos = posMax.back();
            stackMax.pop_back();
            posMax.pop_back();
        }
        stackMax.push_back(a[i]);
        posMax.push_back(lastPos);
        
        lastPos = i;
        while (!stackMin.empty() && stackMin.back() > a[i])
        {
            tree.update(posMin.back(), lastPos - 1, stackMin.back() - a[i]);
            lastPos = posMin.back();
            stackMin.pop_back();
            posMin.pop_back();
        }
        stackMin.push_back(a[i]);
        posMin.push_back(lastPos);
        
        tree.update(1, i - 1, -1);
        
        int id = tree.find(from, i, k);
        if (id && i - id > ans) 
        {
            ans = i - id;
            posAns = id;
        }
    }
    
    cout << posAns << ' ' << posAns + ans << endl;
}