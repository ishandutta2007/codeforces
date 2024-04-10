#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+10;
int n,m;
string s,l;
vi letters[27];
int cnt[27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<26;i++) letters[i].PB(0);
    for(int i=0; i<n;i++) {
		letters[s[i]-'a'].PB(i+1);
	}
	cin>>m;
	while(m--) {
		cin>>l;
		for(int i=0; i<26;i++) cnt[i]=0;
		for(int i=0; i<l.size();i++) cnt[l[i]-'a']++;
		int ans = 0;
		for(int i=0; i<26;i++) ans=max(ans,letters[i][cnt[i]]);
		cout<<ans<<"\n";
	}
}