#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string a[40];
char b[40];
long n,q,i;
map < string , char > mp;
long sol(char ch,long n)
{
    if(n==1) return 1;
    long i,cnt=0;
    for(i=0;i<q;++i)
    if(b[i]==ch) cnt=cnt+sol(a[i][0],n-1);
    return cnt;
}
int main()
{
    io
    cin>>n>>q;
    for(i=0;i<q;++i)
    {
        cin>>a[i]>>b[i];
        mp[a[i]]=b[i];
    }
    cout<<sol('a',n);
    return 0;
}