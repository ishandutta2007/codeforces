//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,ans[100111],tot;
struct TRIE
{
    struct node
    {
        node *child[26];
        vector<int>id;
        node(){for(int i=0;i<26;i++)child[i]=NULL;id.clear();}
    };
    node *root;
    TRIE()
    {
        root=new node;
    }
    void add(string s,int addid)
    {
        node *p=root;
        for(int i=0;i<s.size();i++)
        {
            if(!p->child[s[i]-'a'])p->child[s[i]-'a']=new node;
            p=p->child[s[i]-'a'];
        }
        p->id.PB(addid);
    }
    void dfs(node *p,int lv)
    {
        if(!p)return;
        for(int i=0;i<26;i++)
        {
            dfs(p->child[i],lv+1);
        }
        for(int i=0;i<26;i++)
        {
            if(!p->child[i])continue;
            for(int j=0;j<p->child[i]->id.size();j++)
            {
                p->id.PB(p->child[i]->id[j]);
            }
        }
        sort(p->id.begin(),p->id.end());
        int l=0,r=int(p->id.size())-1;
        while(l<r&&p->id[l]<=n&&p->id[r]>n)
        {
            ans[p->id[l]]=p->id[r];
            l++;r--;tot+=lv;
        }
        vector<int>t;
        for(int i=l;i<=r;i++)t.PB(p->id[i]);
        p->id=t;
    }
}trie;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        string s;
        cin>>s;
        trie.add(s,i);
    }
    trie.dfs(trie.root,0);
    cout<<tot<<endl;
    for(int i=1;i<=n;i++)cout<<i<<" "<<ans[i]-n<<endl;
    return 0;
}