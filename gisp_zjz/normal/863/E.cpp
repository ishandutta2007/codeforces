#include<bits/stdc++.h>
#define maxn 500050
#define inf 1000300400

using namespace std;
set <int> st;
map <int,int> f;
int l[maxn],r[maxn],s[maxn],b[maxn],n,m,a[maxn],k,c[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        l[i]--; b[m++]=l[i]; b[m++]=r[i];
    }
    sort(b,b+m);
    for (int i=0;i<m;i++) if (st.find(b[i])==st.end()) st.insert(b[i]),f[b[i]]=++k;
    for (int i=1;i<=n;i++) l[i]=f[l[i]],r[i]=f[r[i]];
    for (int i=1;i<=n;i++) c[l[i]+1]++,c[r[i]+1]--;
    for (int i=1;i<=k;i++) s[i]=s[i-1]+c[i],a[i]=a[i-1]+(s[i]>1);
    for (int i=1;i<=n;i++) if (r[i]-l[i]==a[r[i]]-a[l[i]]) {cout << i << endl;return 0;}
    cout << -1 << endl;
}