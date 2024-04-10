#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
int n,q,s,a[N],res[N],plc[N],tree[4*N],zp;
bool qexist;
void update(int nd,int l,int r,int x,int v)
{
    if(x<l||r<x) return;
    if(l==r){
        tree[nd]=v;
        return;
    }
    int m=(l+r)/2;
    update(nd*2,l,m,x,v);
    update(nd*2+1,m+1,r,x,v);
    tree[nd]=min(tree[nd*2],tree[nd*2+1]);
}
int query(int nd,int l,int r,int s,int e)
{
    if(r<s||e<l) return 1e9;
    if(s<=l&&r<=e) return tree[nd];
    int m=(l+r)/2;
    return min(query(nd*2,l,m,s,e),query(nd*2+1,m+1,r,s,e));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<4*N;i++) tree[i]=1e9;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==q) qexist=true;
        if(a[i]) update(1,1,n,i,a[i]);
        else zp=i;
    }
    for(s=1;s<=n;s++)
        if(a[s]) break;
    if(s==n+1){
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<q<<" ";
        return 0;
    }
    for(int i=1;i<s;i++)
        res[i]=a[s];
    for(int i=s;i<=n;i++){
        if(!a[i]){
            res[i]=res[i-1];
            continue;
        }
        if(plc[a[i]]){
            if(query(1,1,n,plc[a[i]]+1,i)<a[i]){
                cout<<"NO";
                return 0;
            }
        }
        plc[a[i]]=i;
        res[i]=a[i];
    }
    if(!qexist&&zp) res[zp]=q;
    else if(!qexist){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
    return 0;
}