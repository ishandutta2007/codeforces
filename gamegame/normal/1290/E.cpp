#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+1;
const int ts=1<<21;
int n;
ll mx[ts],se[ts],mxc[ts];//max, 2nd max, max count
int sz;
ll ch[N];//which values are changed
ll df[N];//change in frequency
void pass(int id,int c){
    if(mx[c]>mx[id]) mx[c]=mx[id];
}
void push(int id){
    pass(id,id*2);
    pass(id,id*2+1);
}
void pull(int id){
    mx[id]=max(mx[id*2],mx[id*2+1]);
    mxc[id]=0;
    if(mx[id]==mx[id*2]) mxc[id]+=mxc[id*2];
    if(mx[id]==mx[id*2+1]) mxc[id]+=mxc[id*2+1];
    se[id]=max(se[id*2],se[id*2+1]);
    if(mx[id*2]!=mx[id]) se[id]=max(se[id],mx[id*2]);
    if(mx[id*2+1]!=mx[id]) se[id]=max(se[id],mx[id*2+1]);
}
void upd(int id,int l,int r,int ql,int qr,int v){
    if(l>qr || r<ql || mx[id]<=v) return;
    if(ql<=l && r<=qr && se[id]<v){
	    ch[++sz]=mx[id];df[mx[id]]-=mxc[id];
	    mx[id]=v;
	    ch[++sz]=mx[id];df[mx[id]]+=mxc[id];
	    return;
    }
    push(id);
    int mid=(l+r)/2;
    upd(id*2,l,mid,ql,qr,v);
    upd(id*2+1,mid+1,r,ql,qr,v);
    pull(id);
}
void upd2(int id,int l,int r,int p,int v){
    if(l==r){
	    ch[++sz]=mx[id];df[mx[id]]-=mxc[id];
	    mx[id]=v;
	    ch[++sz]=mx[id];df[mx[id]]+=mxc[id];
	    return;
    }
    push(id);
    int mid=(l+r)/2;
    if(p<=mid) upd2(id*2,l,mid,p,v);
    else upd2(id*2+1,mid+1,r,p,v);
    pull(id);
}
void build(int id,int l,int r){
    mx[id]=0;mxc[id]=r-l+1;se[id]=-1e9;
    if(l==r) return;
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}
/////////////////////////////////////////////////
ll bit1[N],bit2[N];
void bupd1(int id,ll v){
    for(int i=id; i<=n ;i+=i&-i) bit1[i]+=v;
}
void bupd2(int id,ll v){
    for(int i=id; i<=n ;i+=i&-i) bit2[i]+=v;
}
ll bqry1(int id){
    ll res=0;
    for(int i=id; i>=1 ;i-=i&-i) res+=bit1[i];
    return res;
}
ll bqry2(int id){
    ll res=0;
    for(int i=id; i>=1 ;i-=i&-i) res+=bit2[i];
    return res;
}
int a[N],p[N];
ll ans[N];
set<int>s,t;
void magic(int mg){
    s.clear();t.clear();build(1,1,n);
    for(int i=1; i<=n ;i++) bit1[i]=bit2[i]=0;
    s.insert(p[1]);//set of existed elements
    t.insert(p[1]);//set of l that maxr[] is not null
    bupd1(p[1],1);
    int mx=p[1];//largest existed position
    upd2(1,1,n,p[1],p[1]);
    bupd2(p[1],-1);
    ll tot=-1;
    for(int i=2; i<=n ;i++){
	    int cur=p[i];
	    auto it=s.lower_bound(cur);
	    bool rm=(it==s.end());//new element is rightmost
	    int nxt=0;
	    if(!rm) nxt=*it;//next
	    if(it==s.begin()){//new element is leftmost
		    tot-=bqry1(cur);bupd2(cur,-1);
		    t.insert(cur);
		    upd2(1,1,n,cur,mx);
	    }
	    else{
		    int prv=*(--it);
		    upd(1,1,n,1,prv,prv);
		    if(rm) mx=cur;
		    else{
			    upd2(1,1,n,nxt,mx);
			    if(t.find(nxt)==t.end()){
				    tot-=bqry1(nxt);bupd2(nxt,-1);
				    t.insert(nxt);
			    }
		    }
		    upd2(1,1,n,*s.begin(),mx);
	    }
	    s.insert(cur);
	    tot+=bqry2(n)-bqry2(cur-1);
	    bupd1(cur,1);
	    for(int j=1; j<=sz ;j++){
		    if(ch[j]!=0 && df[ch[j]]!=0){
			    tot+=df[ch[j]]*bqry1(ch[j]);
			    bupd2(ch[j],df[ch[j]]);
			    df[ch[j]]=0;
		    }
	    }
	    sz=0;
	    ans[i]+=tot;
    }
}
void solve(){
    for(int i=1; i<=n ;i++){
	    p[a[i]]=i;ans[i]=0;
    }
    magic(1);
    for(int i=1; i<=n ;i++) p[i]=n+1-p[i];
    magic(0);
    for(int i=1; i<=n ;i++) ans[i]+=1;
    for(int i=1; i<=n ;i++) cout << ans[i] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n ;i++) cin >> a[i];
    solve();
}