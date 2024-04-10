/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
void solve(){
	string s;
	cin>>s;
	sort(ALL(s));
	int n=s.length();
	if(s[0]==s[n-1]){
		cout<<s<<endl;
		return ;
	}
	int C[26]={0};
	rep(i,n) C[s[i]-'a']++;
	int mn=INF;
	rep(i,26) if(C[i]!=0) check_min(mn,C[i]);
	if(mn==1){
		char Tmp;
		rep(i,26) if(C[i]==1){
			Tmp='a'+i;
			break;
		}
		string ans;
		ans.PB(Tmp);
		rep(i,n){
			if(s[i]==Tmp){
				Tmp='#';
				continue;
			}
			ans.PB(s[i]);
		}
		cout<<ans<<endl;
		return ;
	}
	int cnt=0;
	rep(i,n) if(s[i]==s[0]) cnt++;
	string ans;
	if(cnt<=(n-cnt)+2){
		ans.PB(s[0]);
		ans.PB(s[0]);
		cnt-=2;
		rep(i,n){
			if(s[i]==s[0]) continue;
			ans.PB(s[i]);
			if(cnt){
				--cnt;
				ans.PB(s[0]);
			}
		}
	}
	else{
		char ano;
		rep(i,n) if(s[i]!=s[0]){
			ano=s[i];
			break;
		}
		if(ano==s[n-1]){
			ans.PB(s[0]);
			rep(i,n-cnt) ans.PB(ano);
			rep(i,cnt-1) ans.PB(s[0]);
		}
		else{
			char ano2;
			rep(i,n) if(s[i]!=s[0]&&s[i]!=ano){
				ano2=s[i];
				break;
			}
			ans.PB(s[0]);
			ans.PB(ano);
			rep(i,cnt-1) ans.PB(s[0]);
			ans.PB(ano2);
			rep(i,n) if(s[i]!=s[0]){
				if(s[i]==ano){
					ano='#';
					continue;
				}
				if(s[i]==ano2){
					ano2='#';
					continue;
				}
				ans.PB(s[i]);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}