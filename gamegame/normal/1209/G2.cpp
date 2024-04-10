#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[200001];
int b[200001];
set<int>s[200001];
struct nd{
    int ans;
    int lz;
    int mn;
    int lmx,rmx,mx;
    nd(){
    	ans=lz=mn=lmx=rmx=mx=0;
	}
	nd(int a,int b,int c,int d,int e,int f){
		ans=a;lz=b;mn=c;lmx=d;rmx=e;mx=f;
	}
};
nd st[524288];
nd pull(nd& x,nd& y){
	nd tot;
	tot.mn=min(x.mn,y.mn);
	if(x.mn==tot.mn) tot.lmx=x.lmx;
	else tot.lmx=max(x.mx,y.lmx);
	if(y.mn==tot.mn) tot.rmx=y.rmx;
	else tot.rmx=max(y.mx,x.rmx);
	tot.mx=max(x.mx,y.mx);
	int lans=(x.mn==tot.mn?x.ans:x.mx);
	int rans=(y.mn==tot.mn?y.ans:y.mx);
	int lr=(x.mn==tot.mn?x.rmx:x.mx);
	int rl=(y.mn==tot.mn?y.lmx:y.mx);
	tot.ans=lans+rans-lr-rl+max(lr,rl);
	return tot;
}
void push(nd& x,nd& y,nd& z){
	y.lz+=x.lz;
	y.mn+=x.lz;
	z.lz+=x.lz;
	z.mn+=x.lz;
	x.lz=0;
}
void upd(int id,int l,int r,int ql,int qr,int v){
	//if(id==1) cout << ql << ' ' << qr << ' ' << v << endl;
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		st[id].lz+=v;st[id].mn+=v;
		return;
	}
	int mid=(l+r)/2;
	push(st[id],st[id*2],st[id*2+1]);
	upd(id*2,l,mid,ql,qr,v);
	upd(id*2+1,mid+1,r,ql,qr,v);
	st[id]=pull(st[id*2],st[id*2+1]);
}
void ping(int id,int l,int r,int p){
//	cout << "ping " << id << endl;
	if(l==r){
		st[id]={b[l]+b[l+1],st[id].lz,st[id].mn,b[l],b[l+1],max(b[l],b[l+1])};
		return;
	}
	push(st[id],st[id*2],st[id*2+1]);
	int mid=(l+r)/2;
	if(p<=mid) ping(id*2,l,mid,p);
	else ping(id*2+1,mid+1,r,p);
	st[id]=pull(st[id*2],st[id*2+1]);
}
void put(int c,int v){
	if(v==1) b[*s[c].begin()]=s[c].size();
	else b[*s[c].begin()]=0;
	if(*s[c].begin()!=n) ping(1,1,n-1,*s[c].begin());
	if(*s[c].begin()!=1) ping(1,1,n-1,*s[c].begin()-1);
	if(s[c].size()>1) upd(1,1,n-1,*s[c].begin(),*s[c].rbegin()-1,v);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> q;
    if(n==1){
    	for(int i=0; i<=q ;i++) cout << "1\n";
    	return 0;
	}
    for(int i=1; i<=n ;i++){
        cin >> a[i];
        if(!s[a[i]].empty()) put(a[i],-1);
        s[a[i]].insert(i);
        put(a[i],1);
    }
    cout << n-(st[1].mn?st[1].mx:st[1].ans) << '\n';
    for(int i=1; i<=q ;i++){
        int x,y;cin >> x >> y;
        put(a[x],-1);s[a[x]].erase(x);
        if(!s[a[x]].empty()) put(a[x],1);
        a[x]=y;
        if(!s[a[x]].empty()) put(a[x],-1);
        s[a[x]].insert(x);put(a[x],1);
        cout << n-(st[1].mn?st[1].mx:st[1].ans) << '\n';
    }
}