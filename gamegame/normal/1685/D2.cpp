#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
int p[N],q[N],s[N],t[N];
int r[N];
bool vis[N];

int ban[N];
int find(int x){
	if(r[x]==x) return x;
	return find(r[x]);
}
void join(int x,int y){
	x=find(x);y=find(y);
	if(x<y) swap(x,y);
	r[x]=y;
}
int el[N],er[N];
bool check(){
	for(int i=1; i<=n ;i++) r[i]=i;
	for(int i=1; i<=n ;i++) join(i,s[i]);
	for(int i=1; i<=n ;i++){
		if(er[i]!=0) join(i,er[i]);
	}
	bool ok=true;
	for(int i=1; i<=n ;i++) if(find(i)!=find(1)) ok=false;
	return ok;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];s[p[i]]=i;
		el[i]=i-1;er[i]=i+1;
	}
	er[n]=0;
	int boss=1;
	s[0]=1e9;
	while(true){
		for(int i=1; i<=n ;i++) r[i]=i,vis[i]=false;
		for(int i=1; i<=n ;i++) join(i,s[i]);
		for(int i=1; i<=n ;i++) t[i]=find(i)==find(1);
		bool fin=true;
		for(int i=1; i<=n ;i++) if(!t[i]) fin=false;
		if(fin) break;
		int l=boss,r=boss;
		{
			for(int i=1; i<=n ;i++) vis[i]=false;
			vis[find(l)]=true;
			while(el[l]!=0 && !vis[find(el[l])]){
				l=el[l];vis[find(l)]=true;
			}
		}
		{
			for(int i=1; i<=n ;i++) vis[i]=false;
			vis[find(r)]=true;
			while(er[r]!=0 && !vis[find(er[r])]){
				r=er[r];vis[find(r)]=true;
			}
		}
		//cout << boss << ' ' << l << ' ' << r << endl;
		int sl=el[boss],sr=er[boss];
		el[boss]=er[boss]=0;
		if(sl!=0) er[sl]=0;
		if(sr!=0) el[sr]=0;
		bool stay=check();
		el[boss]=sl;er[boss]=sr;
		if(sl!=0) er[sl]=boss;
		if(sr!=0) el[sr]=boss;
		int best=0;
		for(int i=boss; i!=l ;i=el[i]){
			if(s[el[i]]<s[best]) best=el[i];
		}
		for(int i=boss; i!=r ;i=er[i]){
			if(s[er[i]]<s[best]) best=er[i];
		}
		if(stay && s[boss]<s[best]){
			er[el[boss]]=0;el[er[boss]]=0;
			el[boss]=0;er[boss]=0;
		}
		else{
			if(best==0) while(true);
			if(best<boss){
				bool fun=(best==el[boss]);
				for(int i=best; i!=boss ;){
					swap(s[i],s[er[i]]);
					int ni=er[i];
					el[ni]=er[i]=0;
					i=ni;
				}
				if(fun){
					er[best]=er[boss];
					if(er[best]!=0) el[er[best]]=best;
					er[boss]=0;
				}
			}
			else{
				bool fun=(best==er[boss]);
				for(int i=best; i!=boss ;){
					swap(s[i],s[el[i]]);
					int ni=el[i];
					er[ni]=el[i]=0;
					i=ni;
				}
				if(fun){
					el[best]=el[boss];
					if(el[best]!=0) er[el[best]]=best;
					el[boss]=0;
					
				}
			}
		}/*
		cout << "solv " << boss << endl;
		for(int i=1; i<=n ;i++) cout << s[i] << ' ';
		cout << endl;
		for(int i=1; i<=n ;i++){
			if(er[i]!=0) cout << i << ' ' << er[i] << endl;
			if(el[i]!=0) cout << i << ' ' << el[i] << endl;
		}*/
		boss=s[boss];
	}
	q[1]=1;
	for(int i=2; i<=n ;i++){
		q[i]=s[q[i-1]];
	}
	for(int i=1; i<=n ;i++) cout << q[i] << ' ';
	cout << '\n';
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}