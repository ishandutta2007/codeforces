#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int modInverse(int a, int m);
int gcd(int a, int b);
int power(int x, unsigned int y, unsigned int m);
void pairsort(int a[], int b[], int n);


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
    int q[n-1];
    int tempq=0;
    int minqi=0;
    int minq=0;
    REP(i,0,n-1)
    {
        cin>>q[i];
        tempq+=q[i];
        if(minq>tempq)
        {
            minq=tempq;
            minqi=i+1;
        }
    }
    int a[n];
    int flag=0;
    int f[n+1]={};
    a[minqi]=1;
    f[1]++;
    REP(i,minqi+1,n)
    {
        a[i]=a[i-1]+q[i-1];
        if(a[i]>=1&&a[i]<=n)f[a[i]]++;
        else flag=1;
    }
    for(int i=minqi-1;i>=0;i--)
    {
        a[i]=a[i+1]-q[i];
        if(a[i]>=1&&a[i]<=n)f[a[i]]++;
        else flag=1;
    }
    REP(i,1,n+1)
    {
        if(f[i]!=1) flag=1;
    }
    if(flag==1) cout<<"-1";
    else
    {
        REP(i,0,n)
        {
            cout<<a[i]<<' ';
        }
    }

    return 0;
}