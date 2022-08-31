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

int xd(char c)
{
    cout<<c<<endl;
    string s;
    cin>>s;
    if(s=="player") return 1;
    else return 0;
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
    char c[3]={'R','P','S'};
    int r[10];
    r[0]=xd('R');
    r[1]=xd('R');
    r[2]=xd('P');
    r[3]=xd('P');
    r[4]=xd('S');
    r[5]=xd('S');
    r[6]=xd('P');
    r[7]=xd('P');
    r[8]=xd('R');
    r[9]=xd('R');

    if(r[0]==0&&r[1]==0&&r[2]==1&&r[3]==1&&r[4]==0&&r[5]==0&&r[6]==1&&r[7]==1&&r[8]==0&&r[9]==0)
    {
        REP(i,0,10)
        {
            xd(c[1]);
        }
    }
    else if(r[0]==0&&r[1]==0&&r[2]==0&&r[3]==0&&r[4]==1&&r[5]==1&&r[6]==0&&r[7]==0&&r[8]==0&&r[9]==0)
    {
        REP(i,0,10)
        {
            xd(c[2]);
        }
    }
    else if(r[0]==1&&r[1]==1&&r[2]==0&&r[3]==0&&r[4]==0&&r[5]==0&&r[6]==0&&r[7]==0&&r[8]==1&&r[9]==1)
    {
        REP(i,0,10)
        {
            xd(c[0]);
        }
    }
    else if(r[0]==0&&r[1]==0&&r[2]==0&&r[3]==1&&r[4]==1&&r[5]==0&&r[6]==1&&r[7]==0&&r[8]==1&&r[9]==0)
    {
        int t=2;
        REP(i,0,10)
        {
            xd(c[t]);
            t++;
            t%=3;
        }
    }
    else if(r[1]==0&&r[2]==1&&r[3]==0&&r[4]==1&&r[5]==0&&r[6]==0&&r[7]==0&&r[8]==0&&r[9]==0)
    {
        int t=1;
        REP(i,0,10)
        {
            xd(c[t]);
            t++;
            t%=3;
        }
    }
    else if(r[1]==0&&r[2]==0&&r[3]==0&&r[4]==0&&r[5]==0&&r[6]==1&&r[7]==0&&r[8]==1&&r[9]==0)
    {
        int t=2;
        REP(i,0,10)
        {
            xd(c[t]);
            t+=2;
            t%=3;
        }
    }
    /*
    if(r[1]==&&r[2]==&&r[3]==&&r[4]==&&r[5]==&&r[6]==&&r[7]==&&r[8]==&&r[9]==)
    {
        REP(i,0,10)
        {
            xd(c[]);
        }
    }
    */

    return 0;
}