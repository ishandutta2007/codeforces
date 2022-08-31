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

int xd1(int i,int n1,int n2)
{
    if(n1==n2)
    {
        return n1;
    }
    cout<<'?'<<' '<<i<<' '<<n1<<' '<<i<<' '<<(n1+n2)/2<<endl;
    int t1;
    cin>>t1;
    if(t1==-1)
    {
        exit(0);
    }
    if(t1%2==1)
    {
        return xd1(i,n1,(n1+n2)/2);
    }

    cout<<'?'<<' '<<i<<' '<<(n1+n2)/2+1<<' '<<i<<' '<<n2<<endl;
    int t2;
    cin>>t2;
    if(t2==-1)
    {
        exit(0);
    }
    if(t2%2==1)
    {
        return xd1(i,(n1+n2)/2+1,n2);
    }

    return -1;
}

int xd2(int i,int n1,int n2)
{
    if(n1==n2)
    {
        return n1;
    }
    cout<<'?'<<' '<<n1<<' '<<i<<' '<<(n1+n2)/2<<' '<<i<<endl;
    int t1;
    cin>>t1;
    if(t1==-1)
    {
        exit(0);
    }
    if(t1%2==1)
    {
        return xd2(i,n1,(n1+n2)/2);
    }

    cout<<'?'<<' '<<(n1+n2)/2+1<<' '<<i<<' '<<n2<<' '<<i<<endl;
    int t2;
    cin>>t2;
    if(t2==-1)
    {
        exit(0);
    }
    if(t2%2==1)
    {
        return xd2(i,(n1+n2)/2+1,n2);
    }

    return -1;
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */


    int n;
    cin>>n;
    int x1=0,x2=0,y1=0,y2=0;
    int flag=0;
    REP(i,1,n+1)
    {
        cout<<'?'<<' '<<i<<' '<<1<<' '<<i<<' '<<n<<endl;
        int t;
        cin>>t;
        if(t==-1)
        {
            exit(0);
        }
        if(t%2==1)
        {
            flag=1;
            int temp=xd1(i,1,n);
            if(x1==0)
            {
                x1=i;
                y1=temp;
            }
            else
            {
                x2=i;
                y2=temp;
            }
        }
    }
    if(flag==1)
    {
        cout<<'!'<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    }
    else
    {
        REP(i,1,n+1)
        {
            cout<<'?'<<' '<<1<<' '<<i<<' '<<n<<' '<<i<<endl;
            int t;
            cin>>t;
            if(t==-1)
            {
                exit(0);
            }
            if(t%2==1&&flag==0)
            {
                int temp=xd2(i,1,n);
                x1=temp;
                x2=temp;
                y1=i;
                flag=1;
            }
            else if(t%2==1&&flag==1)
            {
                y2=i;
            }
        }
        cout<<'!'<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    }

    return 0;
}