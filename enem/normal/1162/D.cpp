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

    int n,m;
    cin>>n>>m;
    int xx=sqrt(n);
    int a[m],b[m];
    vector<int> v[n];
    REP(i,0,m)
    {
        int t1,t2;
        cin>>t1>>t2;
        if(t1>t2)
        {
            int t=t1;
            t1=t2;
            t2=t;
        }
        a[i]=t1;
        b[i]=t2;
        int d=t2-t1;
        if(d>n+t1-t2)
        {
            d=n+t1-t2;
            v[d].PB(t2);
        }
        else
        {
            v[d].PB(t1);
        }
        if(n%2==0&&d==(n/2))
        {
            v[d].PB(t2);
        }
    }
    int flag=0;
    vector<int> lmao;
    REP(i,0,n)
    {
        if(v[i].size()>0)
        {
            if(v[i].size()==1)
            {
                flag=1;
                break;
            }
            else
            {
                sort(v[i].begin(),v[i].end());
                lmao.PB(i);
            }
        }
    }
    if(flag==1)
    {
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=xx;i++)
    {
        if(n%i==0&&i!=n)
        {
            int f=0;
            REP(j,0,lmao.size())
            {
                REP(k,0,v[lmao[j]].size())
                {
                    if(binary_search(v[lmao[j]].begin(),v[lmao[j]].end(),(v[lmao[j]][k]+i-1)%n+1)==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1)
                {
                    break;
                }
            }
            if(f==0)
            {
                flag=1;
                break;
            }
            int ii=n/i;
            if(ii==n||ii==i) continue;
            else
            {
                REP(j,0,lmao.size())
                {
                    REP(k,0,v[lmao[j]].size())
                    {
                        if(binary_search(v[lmao[j]].begin(),v[lmao[j]].end(),(v[lmao[j]][k]+ii-1)%n+1)==0)
                        {
                            f=0;
                            break;
                        }
                    }
                    if(f==0)
                    {
                        break;
                    }
                }
                if(f==1)
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0)
    {
        cout<<"No";
        return 0;
    }
    else
    {
        cout<<"Yes";
        return 0;
    }

    return 0;
}