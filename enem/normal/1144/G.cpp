#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VLL vector<long long>

int modInverse(int a, int m);
int gcd(int a, int b);
int power(int x, unsigned int y, unsigned int m);
void pairsort(int a[], int b[], int n);
int logint(int x,int y);


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

void pairsort(int a[], int b[], int n)
{
    pair<int, int> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

int logint(int x,int y)
{
    int ans=0;
    int a=1;
    for(int i=0;i<x;i++)
    {
        if(x<=a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}

void solvea(int a[],int i,int f[],int x,int y,int n)
{
    if(i==n)
    {
        cout<<"YES\n";
        REP(j,0,n)
        {
            cout<<f[j]<<' ';
        }
        exit(0);
    }
    if(y==-1||a[i]<a[y])
    {
        f[i]=1;
        int t=y;
        y=i;
        solvea(a,i+1,f,x,y,n);
        y=t;
    }
    if(x==-1||a[i]>a[x])
    {
        f[i]=0;
        int t=x;
        x=i;
        solvea(a,i+1,f,x,y,n);
        x=t;
    }
    return;
}

void solveb(int a[],int i,int f[],int x,int y,int n)
{
    if(i==n)
    {
        cout<<"YES\n";
        REP(j,0,n)
        {
            cout<<f[j]<<' ';
        }
        exit(0);
    }
    if(x==-1||a[i]>a[x])
    {
        f[i]=0;
        int t=x;
        x=i;
        solveb(a,i+1,f,x,y,n);
        x=t;
    }
    if(y==-1||a[i]<a[y])
    {
        f[i]=1;
        int t=y;
        y=i;
        solveb(a,i+1,f,x,y,n);
        y=t;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */


    int n;
    cin>>n;
    int a[n];
    REP(i,0,n)
    {
        int t;
        cin>>t;
        a[i]=t;
    }
    int f[n];
    int x=-1,y=-1;
    if(a[0]<100000)solveb(a,0,f,x,y,n);
    else solvea(a,0,f,x,y,n);
    cout<<"NO";
    return 0;
}