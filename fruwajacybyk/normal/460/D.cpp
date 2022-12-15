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

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;

#define max_n 200005


using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	make3(lint,l,r,k);
	if(k==1){
		cout<<l<<endl<<1<<endl<<l<<endl;
	}
	if(k==2){
		if(r-l==1){
			if(l<(l^r)) 
				cout<<l<<endl<<1<<endl<<l<<endl;
			else cout<<(l^r)<<endl<<2<<endl<<l<<" "<<r<<endl;
		}
		else{
			cout<<1<<endl;
			cout<<2<<endl;
			if(l%2==0) cout<<l<<" "<<l+1<<endl;
			else cout<<l+1<<" "<<l+2<<endl;
		}
	}
	if(k==3){
		lint x = 1LL; while(x<=l) x*=2;
		lint y = x/2;
		if(x+y<=r){
			cout<<0<<endl;
			cout<<3<<endl;
			cout<<l<<" "<<x+(l-y)<<" "<<x+y<<endl;
		}
		else{
			cout<<1<<endl;
			cout<<2<<endl;
			if(l%2==0) cout<<l<<" "<<l+1<<endl;
			else cout<<l+1<<" "<<l+2<<endl;
		}
		
	}
	if(k==4){
		if(r-l>3){
			cout<<"0"<<endl;
			cout<<"4"<<endl;
			if(l%2==0) cout<<l<<" "<<l+1<<" "<<l+2<<" "<<l+3<<endl;
			else cout<<l+1<<" "<<l+2<<" "<<l+3<<" "<<l+4<<endl;
		}
		else{
			lint best = r;
			vector<lint> dla;
			FOR(i,1,16){
				int mask = i;
				vector<lint> v; 
				int step = 0;
				while(mask!=0){
					if(mask%2) v.pb(l+step);
					step++;
					mask/=2;
				}
				lint wyn = v[0];
				FOR(i,1,v.size()) wyn=wyn^v[i];
				if(wyn<best){
					best = wyn;
					dla = v;
				}
			}
			cout<<best<<endl;
			cout<<dla.size()<<endl;
			FOR(i,0,dla.size()) cout<<dla[i]<<" ";
			cout<<endl;
		}
	}
	if(k>4){
		cout<<"0"<<endl;
		cout<<"4"<<endl;
		if(l%2==0) cout<<l<<" "<<l+1<<" "<<l+2<<" "<<l+3<<endl;
		else cout<<l+1<<" "<<l+2<<" "<<l+3<<" "<<l+4<<endl;
	}
	return 0;
}