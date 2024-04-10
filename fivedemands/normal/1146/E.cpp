#include<iostream>
using namespace std;
const int iu=1e5+3;
int n,q;
int vl[262144];
bool lz[262144];
bool fp[262144];
int a[100001];
int b[100001];
void push(int id){
	if(lz[id]){
		vl[id*2]=vl[id*2+1]=vl[id];
		fp[id*2]=fp[id*2+1]=false;
		lz[id*2]=lz[id*2+1]=true;
		lz[id]=false;
	}
	if(fp[id]){
		vl[id*2]=1-vl[id*2];vl[id*2+1]=1-vl[id*2+1];
		if(!lz[id*2]) fp[id*2]=!fp[id*2];
		if(!lz[id*2+1]) fp[id*2+1]=!fp[id*2+1];
		fp[id]=false;
	}
	vl[id]=0;
}
void upd(int id,int l,int r,int ql,int qr,int v){
	//cout << "S " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << v << endl;;
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		fp[id]=false;vl[id]=v;lz[id]=true;
		return;
	}
	push(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ql,qr,v);
	upd(id*2+1,mid+1,r,ql,qr,v);
}
void upd2(int id,int l,int r,int ql,int qr){
	//cout << "F " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;;
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		vl[id]=1-vl[id];
		if(!lz[id]) fp[id]=!fp[id];
		return;
	}
	push(id);
	int mid=(l+r)/2;
	upd2(id*2,l,mid,ql,qr);
	upd2(id*2+1,mid+1,r,ql,qr);
}
int qry(int id,int l,int r,int x){
	if(l==r) return vl[id];
	push(id);
	int mid=(l+r)/2;
	if(x<=mid) return qry(id*2,l,mid,x);
	else return qry(id*2+1,mid+1,r,x);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=q ;i++){
		char c;int x;cin >> c >> x;
		if(c=='>'){
			if(x>=0) upd(1,0,iu,x+1,iu,-1);
			else{
				upd2(1,0,iu,0,-x-1);
				upd(1,0,iu,-x,iu,-1);
			}
		}
		else{
			if(x<=0) upd(1,0,iu,-x+1,iu,2);
			else{
				upd2(1,0,iu,0,x-1);
				upd(1,0,iu,x,iu,2);
			}
		}
		//for(int j=1; j<=5 ;j++) cout << qry(1,0,iu,j) << ' ';
		//cout << endl;
	}
	for(int i=1; i<=iu ;i++) b[i]=qry(1,0,iu,i);
	//for(int i=1; i<=5 ;i++) cout << b[i] << ' ';
	//cout << endl;
	for(int i=1; i<=n ;i++){
		int cur=abs(a[i]);int ans;
		if(b[cur]==-1) ans=-abs(a[i]);
		if(b[cur]==0) ans=a[i];
		if(b[cur]==1) ans=-a[i];
		if(b[cur]==2) ans=abs(a[i]);
		cout << ans << ' ';
	}
	cout << endl;
}