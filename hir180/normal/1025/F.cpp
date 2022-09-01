#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
typedef long long ll;
#define mp make_pair
#define fi first
#define sc second
int n,p[3005];
int x[3005],y[3005];
long long ret = 0;
struct event{
	double deg;
	int p;
	bool in;
	event(double a,int b,bool c){
		deg = a,p = b,in = c;
	}
	bool operator<(const event& ev)const{
		return deg < ev.deg;
	}
};
int A[3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]); p[i]=0;
		A[p[i]]++;
	}
	for(int c=1;c<=n;c++){
		vector<event>v;
		int pos[3]={};
		int zan[3]={};
		zan[p[c]]++;
		for(int i=1;i<=n;i++){
			if(i == c) continue;
			double cur = atan2(y[i]-y[c],x[i]-x[c]);
			//assert(-3.14159265<=cur && cur<=3.14159265);
			if(y[i]>=y[c]){
				if(y[i] != y[c] || cur < 0.1){
					pos[p[i]]++;
					v.push_back(event(cur,i,0));
				}
				else{
					v.push_back(event(0,i,1));
				}
			}
			else{
				cur = atan2(y[c]-y[i],x[c]-x[i]);
				v.push_back(event(cur,i,1));
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			int x = v[i].p;
			ll ad = 1;
			if(!v[i].in){
				pos[p[x]]--; zan[p[x]]++;
				int S=0;
				for(int i=0;i<3;i++) if(1) S+=pos[i];
				ad = 1LL*S*(S-1)/2;
				S = 0;
				for(int i=0;i<3;i++) if(1) S += (A[i]-pos[i]-zan[i]);
				ad *= 1LL*S*(S-1)/2;
				ret += ad;
				ad=1;
				S = 0;
				for(int i=0;i<3;i++) if(1) S+=pos[i];
				ad = 1LL*S*(S-1)/2;
				S = 0;
				for(int i=0;i<3;i++) if(1) S += (A[i]-pos[i]-zan[i]);
				ad *= 1LL*S*(S-1)/2;
				ret += ad;
				zan[p[x]]--;
			}
			else{
				zan[p[x]]++;
				int S = 0;
				for(int i=0;i<3;i++) if(1) S+=pos[i];
				ad = 1LL*S*(S-1)/2;
				S = 0;
				for(int i=0;i<3;i++) if(1) S += (A[i]-pos[i]-zan[i]);
				ad *= 1LL*S*(S-1)/2;
				ret += ad;
				ad=1;
				S = 0;
				for(int i=0;i<3;i++) if(1) S+=pos[i];
				ad = 1LL*S*(S-1)/2;
				S = 0;
				for(int i=0;i<3;i++) if(1) S += (A[i]-pos[i]-zan[i]);
				ad *= 1LL*S*(S-1)/2;
				ret += ad;
				pos[p[x]]++; zan[p[x]]--;
			}
		}
	}
	cout << ret/4 << endl;
}