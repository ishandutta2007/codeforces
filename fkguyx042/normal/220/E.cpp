#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<vector>  
#define lowbit(i) (i&(-i))  
#define LL long long   
using namespace std;  
const int N=100005;  
const int M=5000000;  
int n,m,a[N];  
LL k;  
vector<int>v;  
struct persistent_tree{  
    int lson[M],rson[M],c[M],T[M];  
    int tot,m;  
    void Init(int t,int _m){  
        tot=0;m=_m;  
        T[t]=bulid(1,m);  
    }  
    int bulid(int l,int r){  
        int root=tot++;  
        c[root]=0;  
        if(l!=r){  
            int m=(l+r)>>1;  
            lson[root]=bulid(l,m);  
            rson[root]=bulid(m+1,r);  
        }  
        return root;  
    }  
    int update(int root,int pos,int val){  
        int newroot=tot++,tmp=newroot;  
        c[newroot]=c[root]+val;  
        int l=1,r=m;  
        while(l<r){  
            int mid=(l+r)>>1;  
            if(pos<=mid){  
                rson[newroot]=rson[root];  
                lson[newroot]=tot++;  
                newroot=lson[newroot];  
                root=lson[root];  
                r=mid;  
            }  
            else{  
                lson[newroot]=lson[root];  
                rson[newroot]=tot++;  
                newroot=rson[newroot];  
                root=rson[root];  
                l=mid+1;  
            }  
            c[newroot]=c[root]+val;  
        }  
        return tmp;  
    }  
    int query(int root,int l,int r,int L,int R){  
        if(R<L) return 0;  
        if(l==L&&r==R)  
            return c[root];  
        int m=(l+r)>>1;  
        if(R<=m) return query(lson[root],l,m,L,R);  
        else if(L>m) return query(rson[root],m+1,r,L,R);  
        else return query(lson[root],l,m,L,m)+query(rson[root],m+1,r,m+1,R);  
    }  
    void insert(int now,int old,int pos,int val){  
        T[now]=update(T[old],pos,val);  
    }  
}pre,suf;  
int main(){  
    cin>>n>>k;  
    v.push_back(-1);  
    for(int i=1;i<=n;i++){  
        cin>>a[i];  
        v.push_back(a[i]);  
    }  
    sort(v.begin(),v.end());  
    v.resize(unique(v.begin(),v.end())-v.begin());  
    for(int i=1;i<=n;i++)  
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();  
    m=v.size()-1;  
    pre.Init(0,m);  
    suf.Init(m+1,m);  
    for(int i=1;i<=n;i++)   
        pre.insert(i,i-1,a[i],1);  
    for(int i=n;i>=1;i--)   
        suf.insert(i,i+1,a[i],1);  
    LL cur=0,ans=0;  
    for(int i=1;i<=n;i++)  
        cur+=(LL)pre.query(pre.T[i],1,m,a[i]+1,m);   
    for(int i=1,j=2;i<=n;i++){  
        while(j<=n&&cur>k){  
            cur-=(LL)pre.query(pre.T[i],1,m,a[j]+1,m);  
            cur-=(LL)suf.query(suf.T[j],1,m,1,a[j]-1);  
            j++;  
        }  
        ans+=n-j+1;  
        if(j==i+1){  
            cur-=(LL)pre.query(pre.T[i],1,m,a[j]+1,m);  
            cur-=(LL)suf.query(suf.T[j],1,m,1,a[j]-1);  
            j++;  
        }  
        cur+=(LL)pre.query(pre.T[i],1,m,a[i+1]+1,m);  
        cur+=(LL)suf.query(suf.T[j],1,m,1,a[i+1]-1);  
    }  
    cout<<ans<<endl;  
    return 0;  
}