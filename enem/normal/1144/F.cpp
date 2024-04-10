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

void solve(int ff[],int f[],int u[],int v[],int m,int i)
{
    if(ff[i]==0)
    {
        ff[i]=1;
        int t=f[i]%2+1;
        for(int j=lower_bound(u,u+2*m,i)-u;j<upper_bound(u,u+2*m,i)-u;j++)
        {
            if(f[v[j]]==0)
            {
                f[v[j]]=t;
                solve(ff,f,u,v,m,v[j]);
            }
            else if(f[v[j]]!=t)
            {
                cout<<"NO";
                exit(0);
            }
        }
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


    int n,m;
    cin>>n>>m;
    int u[2*m],v[2*m],u0[m],v0[m];
    REP(i,0,m)
    {
        int t1,t2;
        cin>>t1>>t2;
        u[2*i]=t1-1;
        v[2*i]=t2-1;
        u[2*i+1]=t2-1;
        v[2*i+1]=t1-1;
        u0[i]=t1-1;
        v0[i]=t2-2;
    }
    pairsort(u,v,2*m);
    int ff[n]={};
    int f[n]={};
    f[0]=1;
    ff[0]=1;
    for(int j=lower_bound(u,u+2*m,0)-u;j<upper_bound(u,u+2*m,0)-u;j++)
    {
        f[v[j]]=2;
        solve(ff,f,u,v,m,v[j]);
    }
    cout<<"YES\n";
    REP(i,0,m)
    {
        cout<<f[u0[i]]-1;
    }
    return 0;
}