#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
vector<int>v;
void flex(int x){
	if(x!=0) v.push_back(x);
	reverse(s.begin()+1,s.begin()+x+1);
}
int cnt[3];
bool impossible(){
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=2; i<=2*n ;i+=2){
		cnt[s[i-1]+s[i]-96]++;
		cnt[t[i-1]+t[i]-96]--;
	}
	//cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
	if(cnt[0]!=0 || cnt[1]!=0 || cnt[2]!=0) return true;
	else return false;
}
void solve(){
	cin >> s >> t;
	n=s.size()/2;
	s=' '+s;t=' '+t;
	if(impossible()){
		cout << "-1\n";
		return;
	}
	bool old=false;
	for(int i=n-1; i>=1 ;i--){
		if(old){
			for(int j=2*n; j>=2 ;j-=2){
				if(t[2*i]==s[j-1] && t[2*i-1]==s[j]){
					flex(j-2);flex(j);
					break;
				}
			}
		}
		else{
			bool done=false;
			for(int j=2; j<=2*i+2 ;j+=2){
				if(t[2*i-1]==s[j-1] && t[2*i]==s[j]){
					flex(j);flex(2*i+2);
					done=true;break;
				}
			}
			if(done) continue;
			int x=0;
			for(int j=1; j<=i ;j++){
				if(t[2*j-1]==t[2*i-1] && t[2*j]==t[2*i]) x++;
			}
			if(t[2*n]==t[2*i-1] && t[2*n-1]==t[2*i]) x++;
			if(x!=0){
				int cnt=0;
				for(int j=2; j<=2*n ;j+=2){
					cnt+=((s[j-1]+s[j]-96)==1);
					if(cnt==x){
						flex(j);
						break;
					}
				}
			}
			flex(2*n);flex(2*n-2*i-2);i++;old=true;
			//not found lmao
		}
	}
	if(!old){
		if(s[1]==t[2*n-1] && s[2]==t[2*n]) flex(2);
		flex(2*n);flex(2*n-2);
	}
	cout << v.size() << '\n';
	for(auto c:v) cout << c << ' ';
	cout << '\n';
	v.clear();
	//cout << "results\n";
	//cout << s << '\n' << t << '\n';
	//cout << "\\results\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}