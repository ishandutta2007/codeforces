#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
bool pos[27];
bool lol[27];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=26 ;i++){
		pos[i]=true;
	}
	int cnt=26;
	int ans=0;
	for(int i=1; i<=n ;i++){
		char c;
		string s;
		cin >> c >> s;
		if(c=='!'){
			if(cnt==1) ans++;
			for(int i=1; i<=26 ;i++){
				lol[i]=false;
			}
			for(int i=0; i<s.size() ;i++) lol[s[i]-96]=true;
			for(int i=1; i<=26 ;i++){
				if(pos[i] && !lol[i]){
					pos[i]=false;
					cnt--;
				}
			}
		}
		else if(c=='.'){
			for(int i=0; i<s.size() ;i++){
				int cur=s[i]-96;
				if(pos[cur]){
					pos[cur]=false;
					cnt--;
				}
			}
		}
		else{
			int cur=s[0]-96;
			if(cnt==1 && i!=n) ans++;
			if(pos[cur]){
				pos[cur]=false;
				cnt--;
			}
			
		}
	}
	cout << ans << endl;
}