#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int N = 1e6 + 10;
int nxt[N];
map<int , vector<int>> w;
int extendA[N], extendB[N], l[N], r[N];
char s[N], t[N];
int n, m, k;
void pre_EKMP(char x[],int m,int nxt[])
{
    nxt[0]=m;
    int j=0;
    while(j+1<m && x[j]==x[j+1]) j++;
    nxt[1]=j;
    int k=1;
    for(int i=2;i<m;i++)
    {
        int p=nxt[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1)nxt[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<m && x[i+j]==x[j])j++;
            nxt[i]=j;
            k=i;
        }
    }
}
void EKMP(char x[],int m,char y[],int n,int nxt[],int extend[])
{
    pre_EKMP(x,m,nxt);
    int j=0;
    while(j<n && j<m && x[j]==y[j]) j++;
    extend[0]=j;
    int k=0;
    for(int i=1;i<n;i++)
    {
        int p=extend[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1)
            extend[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<n && j<m && y[i+j]==x[j]) j++;
            extend[i]=j;
            k=i;
        }
    }
}

struct node{
    int son[26];
    int len, fail;
    int id;
}tri[N];
int lst, L;
void add(int last,int c){
    static int v,u,up,up1;
    v=++L;
    u=last;
    tri[v].len=tri[u].len+1;
    for (;u&&!tri[u].son[c];u=tri[u].fail)tri[u].son[c]=v;
    if (!u)tri[v].fail=1;
    else{
        up=tri[u].son[c];
        if (tri[up].len==tri[u].len+1)tri[v].fail=up;
        else{
            up1=++L;
            tri[up1]=tri[up];
            tri[up1].len=tri[u].len+1;
            tri[up].fail=tri[v].fail=up1;
            for (;u&&tri[u].son[c]==up;u=tri[u].fail)tri[u].son[c]=up1;
        }
    }
    lst=v;
}
int rt[N];
int main() {
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", s);
    scanf("%s", t);
    lst=1,L=1;
    rt[0] = 1;
    for (int i=0;i<m;i++){
        add(lst,t[i]-'a');
        rt[i + 1] = lst;
    }
    EKMP(t, m, s, n, nxt, extendA);
    reverse(s, s +n);
    reverse(t, t + m);
    EKMP(t, m, s, n, nxt, extendB);
    reverse(extendB, extendB + n);
    for (int i = 0; i < n ; i ++) {
        extendB[i] = min(extendB[i], k), extendA[i] = min(extendA[i], k);
        if (extendA[i] == m) {
            int l = max(i + extendA[i] - k, 0);
            if (l + k + k - 1 < n) {
                puts("Yes");
                printf("%d %d\n", l + 1, l + k + 1);
                return 0;
            }
            l = min(n - 1, i + k - 1);
            if (l - k - k + 1 >= 0) {
                puts("Yes");
                printf("%d %d\n", l - k - k + 2, l - k + 2);
                return 0;
            }
        }
    }
    int last = 1e9;
    for (int i = n -1 ;i >= 0; i --) {
        l[i] = (extendA[i] == k) * k;
        for (auto u:w[i + k - 1])
            last =min(last, u);
        l[i] = max(l[i], i +k - last);
        if (extendA[i]) {
            int x = i + extendA[i] - 1;
            if (x >=(i+k - 1))
                last = i;
            else
                w[x].push_back(i);
        }
    }
    w.clear();
    last = -1e9;
    for (int i=  0;i < n; i ++) {
        r[i] = (extendB[i]==k) * k;
        for (auto u:w[i - k + 1])
            last = max(last ,u);
        r[i] = max(r[i], last - (i - k) );
        if (extendB[i]) {
            int x = i - extendB[i] + 1;
            if (x <= i - k + 1) last = i;
            else
                w[x].push_back(i);
        }
    }
    for (int i = 2 * k - 1; i < n ; i ++) {
        int x = rt[l[i - 2 * k + 1]];
        while (!tri[x].id){
            tri[x].id = i - 2 * k + 2;
            x = tri[x].fail;
        }
        if (tri[rt[m - r[i]]].id)
        {
            puts("Yes");
            printf("%d %d\n", tri[rt[m - r[i]]].id, i - k + 2);
            return 0;
        }
    }
    printf("No");
    return 0;
}