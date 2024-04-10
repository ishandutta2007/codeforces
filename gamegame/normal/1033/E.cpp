#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>lvl[601];
vector<int>nv;// not visited
vector<int>qr;
vector<int>ans;
bool vis[601];
int vc=1;
int badu,badv;
vector<int>up,vp;//u path,v path
int ask(){
	cout << '?' << ' ' << qr.size() << '\n';
	for(int i=0; i<qr.size() ;i++){
		cout << qr[i] << ' ';
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
void findall(int id,int l,int r){
	qr.clear();
	for(int i=l; i<=r ;i++) qr.push_back(nv[i]);
	for(auto cur:lvl[id-1]) qr.push_back(cur);
	int num1=ask();
	qr.clear();
	for(int i=l; i<=r ;i++) qr.push_back(nv[i]);
	int num2=ask();
	if(num1==num2) return;
	if(l==r){
		lvl[id].push_back(nv[l]);
		vis[nv[l]]=true;
		vc++;
		return;
	}
	int mid=(l+r)/2;
	findall(id,l,mid);
	findall(id,mid+1,r);
}
int findedge2(int id,int l,int r,int l2,int r2){
	qr.clear();
	for(int i=l; i<=r ;i++) qr.push_back(lvl[id][i]);
	for(int i=l2; i<=r2 ;i++) qr.push_back(lvl[id][i]);
	int res=ask();
	if(res==0) return 0;
	if(l==r) return lvl[id][l];
	int mid=(l+r)/2;
	int num=findedge2(id,l,mid,l2,r2);
	if(num!=0) return num;
	return findedge2(id,mid+1,r,l2,r2);
}
bool findedge1(int id,int l,int r){
	if(l==r) return false;
	qr.clear();
	for(int i=l; i<=r ;i++) qr.push_back(lvl[id][i]);
	int res=ask();
	if(res==0) return false;
	int mid=(l+r)/2;
	if(findedge1(id,l,mid)) return true;
	if(findedge1(id,mid+1,r)) return true;
	badu=findedge2(id,l,mid,mid+1,r);
	badv=findedge2(id,mid+1,r,l,mid);
	return true;
}
int search(int id,int u,int l,int r){
	qr.clear();
	for(int i=l; i<=r ;i++) qr.push_back(lvl[id][i]);
	qr.push_back(u);
	int res=ask();
	if(res==0) return 0;
	if(l==r){
		return lvl[id][l];
	}
	int mid=(l+r)/2;
	int num=search(id,u,l,mid);
	if(num!=0) return num;
	return search(id,u,mid+1,r);
}
void solve(int id,int u,int v){
	int nu=search(id-1,u,0,lvl[id-1].size()-1);
	int nv=search(id-1,v,0,lvl[id-1].size()-1);
	up.push_back(nu);
	vp.push_back(nv);
	if(nu!=nv) solve(id-1,nu,nv);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	lvl[0].push_back(1);
	vis[1]=true;
	for(int i=1; vc!=n ;i++){
		nv.clear();
		for(int j=1; j<=n ;j++){
			if(!vis[j]) nv.push_back(j);
		}
		findall(i,0,nv.size()-1);
		if(!findedge1(i,0,lvl[i].size()-1)) continue;
		up.push_back(badu);
		vp.push_back(badv);
		solve(i,badu,badv);
		cout << 'N' << ' ' << up.size()+vp.size()-1 << endl;
		for(auto cur:up) cout << cur << ' ';
		for(int j=vp.size()-2; j>=0 ;j--) cout << vp[j] << ' ';
		cout << endl;
		return 0;
	}
	for(int i=0; i<n ;i+=2){
		for(auto cur:lvl[i]) ans.push_back(cur);
	}
	cout << 'Y' << ' ' << ans.size() << '\n';
	for(auto cur:ans) cout << cur << ' ';
	cout << endl;
}