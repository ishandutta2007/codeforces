#include <bits/stdc++.h>
using namespace std;

int n;
string s;

struct SegmentTree
{
    int low, high, mid;
    int openLeft, closeLeft, res;
    SegmentTree *left, *right;
    
    SegmentTree() {}
    
    SegmentTree(int low, int high)
    {
        this -> low = low;
        this -> high = high;
        mid = (low + high) / 2;
        
        if (low == high)
        {
            left = right = NULL;
            openLeft = (s[low] == '(');
            closeLeft = (s[low] == ')');
            res = 0;
        }
        else
        {
            left = new SegmentTree(low, mid);
            right = new SegmentTree(mid + 1, high);
            int newPairs = min(left -> openLeft, right -> closeLeft);
            res = left -> res + right -> res + newPairs;
            openLeft = left -> openLeft + right -> openLeft - newPairs;
            closeLeft = left -> closeLeft + right -> closeLeft - newPairs;
        }
    }
    
    int get(int x, int y, int &open, int &close)
    {
        if (low == x && high == y) 
        {
            open = openLeft;
            close = closeLeft;
            return res;
        }
        
        int resL = 0, openL = 0, closeL = 0, resR = 0, openR = 0, closeR = 0;
        if (x <= mid) resL = left -> get(x, min(y, mid), openL, closeL);
        if (mid < y) resR = right -> get(max(x, mid + 1), y, openR, closeR);
        
        int newPairs = min(openL, closeR);
        open = openL + openR - newPairs;
        close = closeL + closeR - newPairs;
        return resL + resR + newPairs;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> s;
    SegmentTree *root = new SegmentTree(0, s.size() - 1);

    int Q, x, y, z, t;
    cin >> Q;
    while (Q--)
    {
        cin >> x >> y;
        cout << root -> get(--x, --y, z, t) * 2 << endl;
    }
}