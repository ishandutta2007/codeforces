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

const int nax = 300*1000+10,mod=998244353;
int n;
pi p[nax];
int f[nax];
int allcnt=0,cmn = 1;

int count_good(vi t) {
	int w = 1, wsk = 0, last = 0;
	//cout<<"T \n";
	//for(auto it:t) {
	//	cout<<it<<" ";
	//}
	//cout<<"\n";
	while(last<(int)t.size()) {
		while(wsk+1<(int)t.size()&&t[wsk+1]==t[last]) {
			wsk++;
		}
		w = ((ll)w*f[wsk-last+1])%mod;
		//cout<<wsk<<" "<<last<<" "<<f[wsk-last+1]<<"\n";
		last = ++wsk;
	}
	//cout<<"w"<<w<<"\n";
	return w;
}

int main() {_
	cin>>n;
	for(int i=1; i<=n;i++) {
		cin>>p[i].ST>>p[i].ND;
	}
	sort(p+1,p+n+1);
	f[0] = 1;
	for(int i=1; i<=n;i++) {
		f[i] = ((ll)f[i-1]*i)%mod;
	}
	vi tmp;
	for(int j=0; j<2; j++) {
		int sm = 1;
		for(int i=1; i<=n;i++) {
			tmp.PB(p[i].ST);
			swap(p[i].ST,p[i].ND);
		}
		sm = ((ll)sm*count_good(tmp))%mod;
		tmp.clear();
		sort(p+1,p+n+1);
		allcnt=(allcnt+sm)%mod;
		//cout<<allcnt<<"\n";
	}
	bool ok=1;
	for(int i=2; i<=n;i++) {
		if(p[i-1].ND>p[i].ND) {
			ok=0;
		}
	}
	if(!ok) {
		cout<<((ll)f[n]-allcnt+mod)%mod;
		return 0;
	}
	int wsk = 1, last = 1;
	while(last<=n) {
		vi w;
		w.PB(p[last].ND);
		while(wsk+1<=n&&p[wsk+1].ST==p[last].ST) {
			wsk++;
			w.PB(p[wsk].ND);
		}
		cmn = ((ll)cmn*count_good(w))%mod;
		last=++wsk;
	}
	allcnt = ((ll)allcnt-cmn+mod)%mod;
	//cout<<allcnt<<"\n";
	allcnt = ((ll)f[n]-allcnt+mod)%mod;
	cout<<allcnt;
}