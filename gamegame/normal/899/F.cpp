#include<iostream>
#include<set>
#include<queue>
using namespace std;
int n,m;
char a[200001];
set<int>s[128];
set<int>::iterator it;
int bit[200001];
bool hv[200001];
int real(int pos){
	int cur=0,alr=0;
	for(int i=17; i>=0 ;i--){
		if(cur+(1<<i)<=n && alr+bit[cur+(1<<i)]<pos){
			cur+=(1<<i);
			alr+=bit[cur];
		}
	}
	return cur+1;
}
void update(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		s[a[i]].insert(i);
		bit[i]=(i&-i);
		hv[i]=true;
	}
	for(int i=1; i<=m ;i++){
		int ll,rr;
		char c;
		cin >> ll >> rr >> c;
		int l=real(ll),r=real(rr);
		it=s[c].lower_bound(l);
		while(it!=s[c].end() && *it<=r){
			hv[*it]=false;
			update(*it,-1);
			it=s[c].erase(it);
		}
	}
	for(int i=1; i<=n ;i++){
		if(hv[i]) cout << a[i];
	}
}