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
    string s;
    cin>>s;

    if(n%2)
    {
        cout<<":(";
        return 0;
    }

    if(n==2)
    {
        if(s[0]==')')
        {
            cout<<":(";
            return 0;
        }
        else if(s[1]=='(')
        {
            cout<<":(";
            return 0;
        }
        else
        {
            cout<<"()";
            return 0;
        }
    }

    if((s[0]=='('||s[0]=='?')&&(s[1]=='('||s[1]=='?')&&(s[n-2]==')'||s[n-2]=='?')&&(s[n-1]==')'||s[n-1]=='?'))
    {
        s[0]='(';
        s[1]='(';
        s[n-2]=')';
        s[n-1]=')';
    }
    else
    {
        cout<<":(";
        return 0;
    }
    int qsize=0;
    int q[n];
    int l=0;
    int r=0;
    REP(i,0,n)
    {
        if(s[i]=='(') l++;
        else if(s[i]==')') r++;
        else if(s[i]=='?') {q[qsize]=i;qsize++;}
    }
    int qi=0;
    for(;qi<n/2-l;qi++)
    {
        s[q[qi]]='(';
    }
    for(;qi<qsize;qi++)
    {
        s[q[qi]]=')';
    }
    int t=0;
    REP(i,0,n)
    {
        if(s[i]=='(') t++;
        else t--;
        if(t<0)
        {
            cout<<":(";
            return 0;
        }
        else if(t==0&&i!=n-1)
        {
            cout<<":(";
            return 0;
        }
    }
    if(t!=0)
    {
        cout<<":(";
        return 0;
    }
    else cout<<s;

    return 0;
}