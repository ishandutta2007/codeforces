/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int cnt[4];
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		rep(i,4)
			cnt[i]=0;
		string s;
		cin>>s;
		rep(i,s.length()){
			cnt[s[i]-'0']++;
		}
		if(cnt[1]&&cnt[2]&&cnt[3]){
			
		}
		else{
			cout<<0<<endl;
			continue;
		}
		rep(i,4)
			cnt[i]=0;
			int l;
		rep(i,s.length()){
			cnt[s[i]-'0']++;
			if(cnt[1]&&cnt[2]&&cnt[3]){
			l=i;
			break;
		}
		}
		int res=l+1;
		rb(i,1,s.length()-1){
			cnt[s[i-1]-'0']--;
			while(l<s.length()){
				if(cnt[1]&&cnt[2]&&cnt[3]){
					break;	
				}
				l++;
				if(l<s.length())
				cnt[s[l]-'0']++;
			}
			if(l>=s.length()){
				break;
			}
			res=min(res,l-i+1);
		}
		cout<<res<<endl;
	}
	return 0;
}