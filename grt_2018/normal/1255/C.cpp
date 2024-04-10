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

struct Triple {
	int a,b,c;
};

const int nax = 100*1000+100;
int n,last;
int cnt[nax];
vi my[nax];
bool used[nax],done[nax];
Triple t[nax];
int Q[nax],p,k;
		

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>t[i].a>>t[i].b>>t[i].c;
		cnt[t[i].a]++; cnt[t[i].b]++; cnt[t[i].c]++;
		my[t[i].a].PB(i);
		my[t[i].b].PB(i);
		my[t[i].c].PB(i);
	}
	int wsk=-1;
	for(int i=1; i<=n; i++) if(cnt[i]==1) {
		wsk=i;
		if(last==0) last = i;
	}
	used[last]=1;
	Q[k++] = wsk;
	while(p<k) {
		wsk = Q[p++];
		cout<<wsk<<" ";
		used[wsk] = 1;
		for(auto it:my[wsk]) {
			if(done[it]) continue;
			done[it]=1;
			if(t[it].b==wsk) swap(t[it].a,t[it].b);
			if(t[it].c==wsk) swap(t[it].c,t[it].a);
			cnt[t[it].a]--; cnt[t[it].b]--; cnt[t[it].c]--;
			if(cnt[t[it].b]==1) {
				if(!used[t[it].b])
				Q[k++] = t[it].b;
				if(!used[t[it].c])
				Q[k++] = t[it].c;
			} else if(cnt[t[it].c]==1){
				if(!used[t[it].c])
				Q[k++] = t[it].c;
				if(!used[t[it].b])
				Q[k++] = t[it].b;
			}
			used[t[it].c]=1;
			used[t[it].b]=1;
		}
		
	}
	cout<<last;
	
		
}