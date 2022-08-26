#include<bits/stdc++.h>
#define maxn 600000

using namespace std;
int nxt[maxn],m,n,b[maxn],a[maxn],k,c[maxn],r,cnt;
char s[maxn],t[maxn];

void get_nxt()
{
    int i,j;
    j=nxt[0]=-1;
    i=0;
    while (i<m)
        if (j==-1||t[i]==t[j]) nxt[++i]=++j; else j=nxt[j];
}

void kmp_count()
{
    int tmp=0;
    int j=0;
    for (int i=0;i<n;i++)
    {
        while (j>0&&s[i]!=t[j]) j=nxt[j];
        if (s[i]==t[j]) j++;
        while (j>k) j=nxt[j];
        b[i]=j;
        if (j==m) j=nxt[j];
    }
}

int main()
{
    cin >> n >> m >> k;
    scanf("%s",s);scanf("%s",t);
    get_nxt(); kmp_count();
    for (int i=0;i<n;i++) a[i]=b[i];
    reverse(s,s+n); reverse(t,t+m);
    get_nxt(); kmp_count();
    for (int i=1;i<=k;i++)
    {
        if (a[i]>=m||b[i]>=m) {
            puts("Yes");
            cout << 1 << ' ' << n-k+1 << endl;
            return 0;
        }
    }
    cnt=0;
    for (int i=n-k;i>=k;i--)
    {
        c[b[n-i-1]]=i+1;
        r=a[i-1];
        while (!c[m-r]&&r&&cnt<50000000) r=nxt[r],cnt++;
        if (c[m-r]){
            puts("Yes");
            cout << i-k+1 << ' ' << c[m-r] << endl;
            return 0;
        }
    }
    puts("No");
    return 0;
}