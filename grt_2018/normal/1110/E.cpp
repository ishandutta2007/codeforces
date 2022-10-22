#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000*100+1;
int n;
int diff1[MAXN];
int diff2[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int pop; cin>>pop; int f=pop;
	for(int x,i=1; i<n;i++) {
		cin>>x;
		diff1[i-1] = x-pop;
		pop=x;
	}
	cin>>pop;
	int s=pop;
	for(int x,i=1; i<n;i++) {
		cin>>x;
		diff2[i-1] = x-pop;
		pop=x;
	}
	if(s!=f) {
		cout<<"No";
		return 0;
	}
	sort(diff1,diff1+n-1);
	sort(diff2,diff2+n-1);
	for(int i=0; i<n-1; i++) {
		if(diff1[i]!=diff2[i]) {
			cout<<"No"; return 0;
		}
	}
	cout<<"Yes";
	return 0;
}