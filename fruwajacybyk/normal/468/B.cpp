#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define all(x) x.begn(),x.end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)


#define max_n 100005


using namespace std;

vector<int> v;
int n,a,b;
map<int,int> pos;
int kolor[max_n];
int parent[max_n];

int fufind(int x){
	if(x==parent[x]) return x;
	int y = fufind(parent[x]);
	parent[x] = y;
	return y;
}

void fuUnion(int x,int y){
	int xx = fufind(x);
	int yy = fufind(y);
	if(xx!=yy){
		parent[xx] = yy;
	}
}

bool rob(int x,int y){
	if(kolor[x]==-1 && kolor[y]==-1) return true;
	if(kolor[x]!=-1){
		if(kolor[y]==-1){
			kolor[y] = kolor[x];
			return true;
		}
		return (kolor[x]==kolor[y]);
	}
	return rob(y,x);
}

int main(){
	IOS;
	scanf("%d%d%d",&n,&a,&b);
	FOR(i,0,n){
		int c; scanf("%d",&c);
		v.pb(c);
		pos.insert(mp(c,i));
	}

	
	FOR(i,0,n) parent[i] = i;
	FOR(i,0,n) kolor[i] = -1;
	
	FOR(i,0,n){
		if(pos.find(a-v[i])==pos.end() && pos.find(b-v[i])==pos.end()){
			cout<<"NO"<<endl;
			return 0;
		}
		else if(pos.find(a-v[i])==pos.end()){
			kolor[i] = 1;
			int p = pos[b-v[i]];
			fuUnion(i,p);
		}
		else if(pos.find(b-v[i])==pos.end()){
			kolor[i] = 0;
			int p = pos[a-v[i]];
			fuUnion(i,p);
		}
		else{
			int p = pos[a-v[i]];
			int q = pos[b-v[i]];
			fuUnion(p,q);
			fuUnion(p,i);
		}
	}
	
	FOR(i,0,n){
		int zb = fufind(i);
		if(!rob(zb,i)){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	FOR(i,0,n){
		int zb = fufind(i);
		if(!rob(zb,i)){
			cout<<"NO"<<endl;
			return 0;
		}
	}

	cout<<"YES"<<endl;
	FOR(i,0,n){
		if(kolor[i]!=-1) cout<<kolor[i]<<" ";
		else cout<<0<<" ";
	}
	cout<<endl;




	return 0;
}