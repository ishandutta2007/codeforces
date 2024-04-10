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
    int a[1001]={};
    REP(i,0,n*n)
    {
        int t;
        cin>>t;
        a[t]++;
    }
    VI f4,f2,f1;
    REP(i,0,1001)
    {
        int t=a[i];
        if(t%4!=0&&t%2!=0)
        {
            f1.PB(i);
            t--;
        }
        if(t%4!=0)
        {
            f2.PB(i);
            t-=2;
        }
        while(t)
        {
            f4.PB(i);
            t-=4;
        }
    }
    if(n%2)
    {
        if(f1.size()>1||f2.size()>n-1||f2.size()%2)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES\n";
            int ans[n][n];
            while(f2.size()<n-1)
            {
                int t=f4[f4.size()-1];
                f4.pop_back();
                f2.PB(t);
                f2.PB(t);
            }
            REP(i,0,n/2)
            {
                REP(j,0,n/2)
                {
                    int t=f4[i*(n/2)+j];
                    ans[i][j]=t;
                    ans[i][n-1-j]=t;
                    ans[n-1-i][j]=t;
                    ans[n-1-i][n-1-j]=t;
                }
            }
            REP(i,0,n/2)
            {
                int t=f2[i];
                ans[n/2][i]=t;
                ans[n/2][n-1-i]=t;
            }
            REP(i,0,n/2)
            {
                int t=f2[n/2+i];
                ans[i][n/2]=t;
                ans[n-1-i][n/2]=t;
            }
            ans[n/2][n/2]=f1[0];
            REP(i,0,n)
            {
                REP(j,0,n)
                {
                    cout<<ans[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
    }
    else
    {
        if(f1.size()>0||f2.size()>0)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES\n";
            int ans[n][n];
            REP(i,0,n/2)
            {
                REP(j,0,n/2)
                {
                    int t=f4[i*(n/2)+j];
                    ans[i][j]=t;
                    ans[i][n-1-j]=t;
                    ans[n-1-i][j]=t;
                    ans[n-1-i][n-1-j]=t;
                }
            }
            REP(i,0,n)
            {
                REP(j,0,n)
                {
                    cout<<ans[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
    }


    return 0;
}