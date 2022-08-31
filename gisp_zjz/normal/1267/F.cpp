#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
const int maxn=2e5+13;
int n,m,p,q,a[maxn],b[maxn],d[maxn],pa,pb;
bool va[maxn],vb[maxn];
priority_queue <int, vector<int>, greater<int> > Q;
vector <pi> ans;
int main(){
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for (int i=1;i<=p;i++) scanf("%d",&a[i]);
    for (int i=1;i<=q;i++) scanf("%d",&b[i]);
    if (p>=m||q>=n) {puts("No");return 0;}
    for (int i=p+1;i<=m-1;i++) a[i]=n;
    for (int i=q+1;i<=n-1;i++) b[i]=n+m;
    for (int i=1;i<=n+m;i++) d[i]++;
    for (int i=1;i<=m-1;i++) d[a[i]]++;
    for (int i=1;i<=n-1;i++) d[b[i]]++;
    for (int i=1;i<=n+m;i++) if (d[i]==1) Q.push(i);
    for (int i=1;i<=n+m-2;i++){
        int u=Q.top(),v; Q.pop();
        if (u<=n) v=b[++pb]; else v=a[++pa];
        ans.pb((pi){u,v}); d[v]--;
        if (d[v]==1) Q.push(v);
    }
    int u=Q.top(); Q.pop();
    int v=Q.top(); ans.pb((pi){u,v});
    puts("Yes");
    for (auto x:ans) printf("%d %d\n",x.F,x.S);
    return 0;
}