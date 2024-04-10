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
    string ls,rs;
    cin>>ls>>rs;
    int l[27]={},r[27]={};
    REP(i,0,n)
    {
        if(ls[i]!='?') l[ls[i]-'a']++;
        else l[26]++;
        if(rs[i]!='?') r[rs[i]-'a']++;
        else r[26]++;
    }
    int ldiff=0;
    int rdiff=0;
    int ans=0;
    int lans[n];
    int rans[n];
    int lc[27]={};
    int rc[27]={};
    int lcount[27]={};
    int rcount[27]={};
    int c=0;
    REP(i,0,26)
    {
        ans+=min(l[i],r[i]);
        for(;c<ans;c++)
        {
            string lss=ls.substr(lc[i],n-lc[i]);
            lans[c]=lss.find('a'+i)+lc[i];
            string rss=rs.substr(rc[i],n-rc[i]);
            rans[c]=rss.find('a'+i)+rc[i];
            lc[i]=lans[c]+1;
            rc[i]=rans[c]+1;
            lcount[i]++;
            rcount[i]++;
        }
        if(l[i]>r[i]) ldiff+=l[i]-r[i];
        else rdiff+=r[i]-l[i];
    }
    if(l[26]<rdiff||r[26]<ldiff)
    {
        ans+=min(l[26],rdiff);
        for(;c<ans;c++)
        {
            string lss=ls.substr(lc[26],n-lc[26]);
            lans[c]=lss.find('?')+lc[26];
            for(int i=0;i<26;i++)
            {
                if(rcount[i]<r[i])
                {
                    string rss=rs.substr(rc[i],n-rc[i]);
                    rans[c]=rss.find('a'+i)+rc[i];
                    rc[i]=rans[c]+1;
                    rcount[i]++;
                    break;
                }
            }
            lc[26]=lans[c]+1;
        }
        ans+=min(r[26],ldiff);
        for(;c<ans;c++)
        {
            string rss=rs.substr(rc[26],n-rc[26]);
            rans[c]=rss.find('?')+rc[26];
            for(int i=0;i<26;i++)
            {
                if(lcount[i]<l[i])
                {
                    string lss=ls.substr(lc[i],n-lc[i]);
                    lans[c]=lss.find('a'+i)+lc[i];
                    lc[i]=lans[c]+1;
                    lcount[i]++;
                    break;
                }
            }
            rc[26]=rans[c]+1;
        }
    }
    else
    {
        ans+=rdiff;
        for(;c<ans;c++)
        {
            string lss=ls.substr(lc[26],n-lc[26]);
            lans[c]=lss.find('?')+lc[26];
            for(int i=0;i<26;i++)
            {
                if(rcount[i]<r[i])
                {
                    string rss=rs.substr(rc[i],n-rc[i]);
                    rans[c]=rss.find('a'+i)+rc[i];
                    rc[i]=rans[c]+1;
                    rcount[i]++;
                    break;
                }
            }
            lc[26]=lans[c]+1;
        }
        ans+=ldiff;
        for(;c<ans;c++)
        {
            string rss=rs.substr(rc[26],n-rc[26]);
            rans[c]=rss.find('?')+rc[26];
            for(int i=0;i<26;i++)
            {
                if(lcount[i]<l[i])
                {
                    string lss=ls.substr(lc[i],n-lc[i]);
                    lans[c]=lss.find('a'+i)+lc[i];
                    lc[i]=lans[c]+1;
                    lcount[i]++;
                    break;
                }
            }
            rc[26]=rans[c]+1;
        }
        ans+=min(l[26]-rdiff,r[26]-ldiff);
        for(;c<ans;c++)
        {
            string lss=ls.substr(lc[26],n-lc[26]);
            lans[c]=lss.find('?')+lc[26];
            string rss=rs.substr(rc[26],n-rc[26]);
            rans[c]=rss.find('?')+rc[26];
            lc[26]=lans[c]+1;
            rc[26]=rans[c]+1;
        }
    }
    cout<<ans<<'\n';
    REP(i,0,ans)
    {
        cout<<lans[i]+1<<' '<<rans[i]+1<<'\n';
    }
    return 0;
}