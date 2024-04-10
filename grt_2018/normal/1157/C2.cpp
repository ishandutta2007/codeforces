#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 2*100*1000+1;
int n;
int a[nax];
vi moves;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
	}
	int last=0,l=0,r=n-1;
	while(1) {
		if(a[l]>last&&a[r]<=last) {
			moves.PB(0);
			last = a[l];
			l++;
		}
		else if(a[r]>last&&a[l]<=last) {
			moves.PB(1);
			last=a[r];
			r--;
		}
		else if(a[r]>last&&a[l]>last) {
			if(a[r]<a[l]) {
				moves.PB(1);
				last=a[r];
				r--;
			}
			else if(a[r]>a[l]){
				moves.PB(0);
				last=a[l];
				l++;
			}
			else {
				vi lewo={0},prawo={1};
				int tmp=l;
				while(tmp<=r&&a[tmp+1]>a[tmp]) {
					lewo.PB(0);
					tmp++;
				}
				tmp=r;
				while(tmp>=l&&a[tmp-1]>a[tmp]) {
					prawo.PB(1);
					tmp--;
				}
				if(lewo.size()<prawo.size()) lewo.swap(prawo);
				for(auto it:lewo) {
					moves.PB(it);
				}
				break;
			}
		}
		else {
			break;
		}
		if(l>r) break;
	}
	cout<<(int)moves.size()<<"\n";
	for(auto it:moves) {
		if(it) cout<<"R";
		else cout<<"L";
	}
}