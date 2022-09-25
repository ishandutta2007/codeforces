// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

string s;
int cnt[26];
int temp[26];

string solve(int i,int j){
	if (i==j){
		if (cnt[i]<2) return "";
	}
	else{
		if (cnt[i]<1 || cnt[j]<1) return "";
	}
	
	rep(x,0,26) temp[x]=cnt[x];
	temp[i]--;
	temp[j]--;
	
	string res="";
	res+='a'+i;
	res+='a'+j;
	
	int other=0;
	rep(x,0,26) if (x!=i) other+=temp[x];
	
	if (other<temp[j]) return "";
	
	rep(zzz,2,sz(s)){
		if (res.back()!='a'+i) other=max(other-1,0LL);
		rep(x,0,26) if (temp[x]){
			temp[x]--;
			if (other<temp[j] || (res.back()=='a'+i && x==j)) temp[x]++;
			else{
				res+='a'+x;
				break;
			}
		}
	}
	
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>s;
		
		memset(cnt,0,sizeof(cnt));
		rep(x,0,sz(s)) cnt[s[x]-'a']++;
		
		int num=0;
		int mn=1e9;
		rep(x,0,26) if (cnt[x]){
			mn=min(mn,cnt[x]);
			num++;
		}
		
		if (num==1){
			cout<<s<<endl;
		}
		else if (mn==1){
			rep(x,0,26) if (cnt[x]==1){
				cnt[x]--;
				cout<<(char)('a'+x);
				break;
			}
			
			rep(x,0,26) rep(y,0,cnt[x]) cout<<(char)('a'+x);
			cout<<endl;
		}
		else{
			rep(x,0,26*26){
				string ans=solve(x/26,x%26);
				if (ans!=""){
					cout<<ans<<endl;
					break;
				}
			}
		}
	}
}