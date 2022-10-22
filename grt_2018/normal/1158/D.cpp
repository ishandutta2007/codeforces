#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) ((LL)(a.x-b.x)*(a.y-c.y)-(LL)(a.x-c.x)*(a.y-b.y))

struct Point {
	int x,y;
};

const int nax = 2000+10;
const int INF = 1000*1000*1000;
int n;
string s;
Point p[nax];
bool visited[nax];
vi ans;
int id;
Point start={INF,INF};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>p[i].x>>p[i].y;
		if(start.y>p[i].y||(start.y==p[i].y&&p[i].x<start.x)) {
			start=p[i];
			id=i;
		}
	}
	cin>>s;
	ans.PB(id+1);
	for(int i=0; i<n-2; i++) {
		visited[id]=1;
		Point m;
		if(s[i]=='L') {
			m = p[id];
			for(int j=0; j<n;j++) {
				if(!visited[j]) {
					if(DET(start,p[j],m)>=0) {
						m = p[j];
						id=j;
					}
				}
			}
		}
		else {
			m=p[id];
			for(int j=0; j<n;j++) {
				if(!visited[j]) {
					if(DET(start,p[j],m)<=0) {
						m=p[j];
						id=j;
					}
				}
			}
		}
		start = m;
		ans.PB(id+1);
		visited[id]=1;
	}
	for(int i=0; i<n;i++) {
		if(!visited[i]) {
			ans.PB(i+1);
		}
	}
	for(auto it:ans) {
		cout<<it<<" ";
	}
}