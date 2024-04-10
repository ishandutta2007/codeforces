#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long

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

    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }
    int flag=1;
    for(int i=0;i<n+m-1;i++)
    {
        int um;
        if(i<min(n,m)) um=i+1;
        else if(i>=min(n,m)&&i<max(n,m)) um=min(n,m);
        else um=n+m-i-1;
        int chk[um][2]={};
        if(i<min(n,m))
        {
            for(int j=0;j<um;j++)
            {
                chk[j][0]=a[j][i-j];
            }
            for(int j=0;j<um;j++)
            {
                int f=1;
                for(int k=0;k<um;k++)
                {
                    if(chk[k][0]==b[j][i-j]&&chk[k][1]==0)
                    {
                        chk[k][1]++;
                        f=0;
                        break;
                    }
                }
                if(f==1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        else if(i>=min(n,m)&&i<max(n,m))
        {
            if(n>=m)
            {
                for(int j=0;j<um;j++)
                {
                    chk[j][0]=a[i-m+1+j][m-1-j];
                }
                for(int j=0;j<um;j++)
                {
                    int f=1;
                    for(int k=0;k<um;k++)
                    {
                        if(chk[k][0]==b[i-m+1+j][m-1-j]&&chk[k][1]==0)
                        {
                            chk[k][1]++;
                            f=0;
                            break;
                        }
                    }
                    if(f==1)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                {
                    break;
                }
            }
            else
            {
                for(int j=0;j<um;j++)
                {
                    chk[j][0]=a[j][i-j];
                }
                for(int j=0;j<um;j++)
                {
                    int f=1;
                    for(int k=0;k<um;k++)
                    {
                        if(chk[k][0]==b[j][i-j]&&chk[k][1]==0)
                        {
                            chk[k][1]++;
                            f=0;
                            break;
                        }
                    }
                    if(f==1)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                {
                    break;
                }
            }
        }
        else
        {
            for(int j=0;j<um;j++)
            {
                chk[j][0]=a[i-m+1+j][m-1-j];
            }
            for(int j=0;j<um;j++)
            {
                int f=1;
                for(int k=0;k<um;k++)
                {
                    if(chk[k][0]==b[i-m+1+j][m-1-j]&&chk[k][1]==0)
                    {
                        chk[k][1]++;
                        f=0;
                        break;
                    }
                }
                if(f==1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
    }
    if(flag==1) cout<<"YES";
    else cout<<"NO";

    return 0;
}