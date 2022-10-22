#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
 
const int INF = 1e9;
string s;
int cnt[10][10][11];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int x = 0; x<=9; x++) {
		for(int y=0; y<=9;y++) {
			for(int i=0; i<11;i++) cnt[x][y][i] = INF;
			for(int a=0; a<=99;a++) {
				for(int b=0; b<=99;b++) {
				    if(a==0&&b==0) continue;
					cnt[x][y][((a*x)+(b*y))%10] = min(cnt[x][y][((a*x)+(b*y))%10],a+b);
				}
			}
		}
	}
	for(int x=0; x<=9; x++) {
		for(int y=0; y<=9;y++) {
			int ans = 0;
			for(int i=1; i<s.size();i++) {
				int f = s[i-1]-'0', f2 = s[i]-'0';
				int dist = -1;
				if(f<=f2) dist = f2-f;
				else dist = 10-f+f2;
				ans+=cnt[x][y][dist]-1;
				if(ans>=INF) break;
			}
			if(ans>=INF-1) cout<<"-1 ";
			else cout<<ans<<" ";
		}
		cout<<"\n";
	}
				
}