#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int M=1000000007;
const int maxn=6e5+5;
char s[maxn];
int a[maxn],b[maxn],n,tot,m,p[maxn],c[maxn],cnt[26],st[maxn],top;
bool vis[maxn];
vector <pi> ans,res;
void add(int x,int y){
    //cout<<x<<' '<<y<<endl;
    while (x<=n*2) b[x]+=y,x+=x&(-x);
}
int qry(int x){
    int ret=0;
    while (x) ret+=b[x],x-=x&(-x);
    return ret;
}
int nowid(){
    for (int i=0;i<26;i++) if (cnt[i]>=tot/2) return i;
    return -1;
}
void solve(int m){
    //cout<<m<<endl;
    int id=-1; tot=m;
    top=0;
    int x=-1;
    for (int i=1;i<=m;i++){
        st[++top]=i;
        if (x==-1) x=nowid();
        if (x==-1){
            if (top>1&&c[st[top-1]]!=c[st[top]]) {
                int u=st[top-1],v=st[top];
                res.pb((pi){u,v});
                cnt[c[u]]--; cnt[c[v]]--;
                top-=2; tot-=2;
            }
        } else {
            if (top>1&&((c[st[top-1]]==x)^(c[st[top]]==x))) {
                int u=st[top-1],v=st[top];
                res.pb((pi){u,v});
                cnt[c[u]]--; cnt[c[v]]--;
                top-=2; tot-=2;
            }
        }
        //for (int j=1;j<=top;j++)cout<<c[st[j]]<<' ';cout<<" NOWID: " << x<<endl;
    }
    while (top) res.pb((pi){st[top],-1}),top--;
}
void solve(int l,int r){
    //cout<<l<<" "<<r<<endl;
    int L=qry(l),R=qry(r);
    add(r,L-R);
    ans.pb((pi){L+1,R});
}
int main(){
    int _;scanf("%d",&_);
    while (_--){
        scanf("%s",s+1);
        n=strlen(s+1); m=0; res.clear(); ans.clear();
        for (int i=1;i<n;i++) if (s[i]==s[i+1]) p[++m]=i;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=m;i++) c[i]=s[p[i]]-'a',cnt[c[i]]++,vis[i]=0;
        solve(m);
        for (int i=1;i<=n*2;i++) b[i]=0;
        for (int i=1;i<=n;i++) add(i,1);
        for (auto x:res){
            if (x.S==-1) solve(p[x.F],n);
            else solve(p[x.F],p[x.S]);
        }
        solve(0,n);
        printf("%d\n",ans.size());
        for (auto x:ans) printf("%d %d\n",x.F,x.S);
    }
    return 0;
}