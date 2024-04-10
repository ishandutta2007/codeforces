#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Array{                                     //
    int tme,a[100010],t[100010],maxsize;
    ll sum; //tatimemaxnsum
    void clear(){tme++,maxsize=sum=0;}              //++(O(1))
    void inc(int k){
        if(t[k]!=tme)a[k]=0,t[k]=tme;           //
        a[k]++;
        if(a[k]>maxsize)sum=0,maxsize=a[k];
        if(a[k]==maxsize)sum+=k;
    }
    ll ans(){return sum;}
}a;
int head[100010],nxt[200010],cnt,v[200010];
int c[100010],wson[100010],fa[100010],s[100010];
ll ans[100010];
void add(int U,int V){            //
    nxt[++cnt]=head[U];
    head[U]=cnt;
    v[cnt]=V;
}
void dfs1(int now){               //
    s[now]=1;
    wson[now]=0;
    for(register int i=head[now];i;i=nxt[i])
        if(v[i]!=fa[now]){
            fa[v[i]]=now;
            dfs1(v[i]);
            s[now]+=s[v[i]];
            if(s[v[i]]>s[wson[now]])wson[now]=v[i];
        }
}
void dfs2(int now,Array& a){  //now
    a.inc(c[now]);
    for(register int i=head[now];i;i=nxt[i])
        if(v[i]^fa[now])dfs2(v[i],a);
}
void dfs3(int now,Array& a){  //
    if(wson[now]==0){    //
        ans[now]=c[now];
        a.inc(c[now]);
        return;
    }
    for(register int i=head[now];i;i=nxt[i]){
        if(v[i]!=fa[now]&&v[i]!=wson[now]){
            dfs3(v[i],a);
            a.clear();
        }
    }
    dfs3(wson[now],a);  //
    for(register int i=head[now];i;i=nxt[i]){  //
        if(v[i]!=fa[now]&&v[i]!=wson[now]){
            dfs2(v[i],a);
        }
    }
    a.inc(c[now]);  //
    ans[now]=a.ans();//
}
int main(int argc,char**argv){ //
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)scanf("%d",c+i);
    for(register int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1);
    dfs3(1,a);
    for(register int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}