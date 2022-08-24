#include<iostream>
#include<map>
using namespace std;
int q;
int par[400001],dif[400001];
map<int,int>m;
int sz=0;
void find(int id){
	if(id==par[id]) return;
	find(par[id]);
	dif[id]^=dif[par[id]];
	par[id]=par[par[id]];
}
void join(int u,int v,int x){
	find(u);
	find(v);
	if(par[u]==par[v]) return;
	int num=dif[u]^dif[v]^x;
	dif[par[v]]=num;
	par[par[v]]=par[u];
	
}
int main(){
	ios::sync_with_stdio(false);
	int last=0;
	cin >> q;
	for(int i=1; i<=q ;i++){
		int t,l,r,x;
		cin >> t >> l >> r;
		//cout << t << ' ';
		l^=last;
		r^=last;
		if(l>r) swap(l,r);
		r++;
		if(m[l]==0){
			++sz;
			par[sz]=sz;
			m[l]=sz;
		}
		if(m[r]==0){
			++sz;
			par[sz]=sz;
			m[r]=sz;
		}
		//cout << l << ' ' << r-1 << ' ';
		l=m[l];
		r=m[r];
		if(t==1){
			cin >> x;
			x^=last;
			join(l,r,x);
		}
		else{
			find(l);find(r);
			if(par[l]!=par[r]){
				cout << "-1\n";
				last=1;
			}
			else{
				last=(dif[l]^dif[r]);
				cout << last << '\n';
			}
		}
	}
}