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
#define RFOR(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define SZ(a) a.size()
#define LL long long

const int md = 1000000000+7;

int gcd(int a, int b)
{
    while (a) {b%=a; swap(a,b);}
    return b;
}

const int N = 524288;
int n,q;
int a[N];

struct tree
{
    int A[2*N];
    
    void init()
    {
        FOR (i,0,n) A[i+N] = a[i];
        RFOR(i,N,0) A[i] = gcd(A[2*i],A[2*i+1]);
    }
    
    void change(int pos, int val)
    {
        pos += N-1;
        A[pos] = val;
        int i = pos/2;
        while (i)
        {
            A[i] = gcd(A[2*i],A[2*i+1]);
            i /= 2;
        }
    }
    
    bool okey(int pos, int val)
    {
        //cout << pos << " "<<val<<endl;
        if (pos >= N) return true;
        if (A[2*pos]%val != 0 && A[2*pos+1]%val != 0) return false;
        if (A[2*pos]%val != 0) return okey(2*pos, val);
        else return okey(2*pos+1, val);
    }
    
    bool ok(int l, int r, int val)
    {
        l += N-1; r += N-1;
        bool o = 1;
        while (l <= r)
        {
            if (l%2 == 1)
            {
                int vq = A[l];
                if (vq%val != 0)
                {
                    if (!o) return 0;
                    o = 0;
                    if (!okey(l,val)) return 0;
                }
                l++;
            }
            if (r%2 == 0)
            {
                int vq = A[r];
                if (vq%val != 0)
                {
                    if (!o) return 0;
                    o = 0;
                    if (!okey(r,val)) return 0;
                }
                r--;
            }
            l /= 2; r /= 2;
        }
        return 1;
    }
} T;

int main()
{
    scanf("%d",&n);
    FOR (i,0,n) scanf("%d",a+i);
    T.init();
    scanf("%d",&q);
    FOR (i,0,q)
    {
        int type,x,y,z;
        scanf("%d",&type);
        if (type == 2)
        {
            scanf("%d%d",&x,&y);
            T.change(x,y);
        }
        else
        {
            scanf("%d%d%d",&x,&y,&z);
            if (T.ok(x,y,z)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}