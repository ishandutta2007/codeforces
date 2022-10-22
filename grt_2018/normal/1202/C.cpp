#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int T;
string s;
vi px,py;
int maxx,maxy,minx,miny;

int main() {_
	cin>>T;
	while(T--) {
		cin>>s;
		px.clear(); py.clear(); px.PB(0); py.PB(0);
		maxx = maxy = minx = miny = 0;
		for(auto it:s) {
			if(it=='W') py.PB(py.back()+1);
			else if(it=='S') py.PB(py.back()-1);
			else if(it=='D') px.PB(px.back()+1);
			else px.PB(px.back()-1);
			maxx = max(maxx,px.back());
			maxy = max(maxy,py.back());
			minx = min(minx,px.back());
			miny = min(miny,py.back());
		}
		int w = maxy-miny+1,h=maxx-minx+1;
		ll ans = (ll)w*h;
		int l = 0, f = -1;
		for(int i=0; i<(int)px.size();i++) {
			if(px[i] == maxx) l = i;
			if(f==-1&&px[i]==minx) f = i;
		}
		//cout<<"1 : "<<l<<" "<<f<<"\n";
		if(l<f) ans=min(ans,(ll)max(h-1,2)*w);
		l = 0; f = -1;
		for(int i=0; i<(int)px.size();i++) {
			if(px[i] == minx) l = i;
			if(f==-1&&px[i]==maxx) f = i;
		}
		//cout<<"2 : "<<l<<" "<<f<<"\n";
		if(l<f) ans=min(ans,(ll)max(h-1,2)*w);
		l = 0; f = -1;
		for(int i=0; i<(int)py.size();i++) {
			if(py[i] == maxy) l = i;
			if(f==-1&&py[i]==miny) f = i;
		}
		//cout<<"3 : "<<l<<" "<<f<<"\n";
		if(l<f) ans=min(ans,(ll)max(w-1,2)*h);
		l = 0; f = -1;
		for(int i=0; i<(int)py.size();i++) {
			if(py[i] == miny) l = i;
			if(f==-1&&py[i]==maxy) f = i;
		}
		//cout<<"4 : "<<l<<" "<<f<<"\n";
		if(l<f) ans=min(ans,(ll)max(w-1,2)*h);
		if(px.size()>1&&py.size()>1) {
			cout<<ans<<"\n";
		} else {
			cout<<max(ans,(ll)2)<<"\n";
		}
	}
}