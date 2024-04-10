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
const LL INF=1e18;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
#define int LL
int n,k;
int check(int num){
//	int cnt=0;
	if(num%9==0){
		return num/9; 
	}
	return 0;//
//	while(num){
//		if(num%10==9) cnt++;
//		else{
//			return 0;
//		}
//		num/=10;
//	}
//	return cnt;
}
int check2(int num,int k){
	int res=0;
	rb(i,num,num-1+k){
		int tmp=i;
		while(tmp){
			res+=tmp%10;
//			cout<<tmp<<endl;
			tmp/=10;
		}
//		cout<<res<<endl;
	}
	return res;
}
string Min(string s1,string s2){
	if(s1==":"){
		return s2;
	}
	else{
		if(s1.length()<s2.length()){
			return s1;
		}
		if(s1.length()>s2.length()){
			return s2;
		}
		return min(s1,s2);
	}
}
void solve(){
	cin>>n>>k;
	string res=":";
	k++;
	rb(i,0,n){
		int save=n;
		n-=(k*(i+i+k-1))/2;
		if(n>0){
			n=save;
			continue;
		}
		if(n==0){
			LL base=1;
			string tmp="";
			int rest=i;
			while(rest){
				if(rest+k-1<10&&base==1){
					tmp+=char('0'+rest);
					rest=0;
					break;
				}
				if(base==1){
					tmp+=char('0'+9-k+1);
					base*=10;
					rest-=9-k+1;				
				}
				else{
					tmp=char('0'+min(9ll,rest))+tmp;
					base*=10;
					rest-=min(9ll,rest);
				}
//					cout<<rest<<endl;
			}
			if(tmp==""){
				tmp="0";
			}
			res=Min(res,tmp);
		}
		else{//
//			if(i==23){
//				cout<<n<<endl;
//			} 
			n=-n;
			rb(j,1,n-1){
				if(j>k-1) continue;
				if(n%j==0&&check(n/j)){
					int tmp=check(n/j);
					tmp--;
					int fi=k-j;
					fi--;
					int rest=i;
					rest-=tmp*9;
					rest-=9-fi;
					if(rest>=0){
						LL base=10;
						string tt="";
						tt+=char('0'+9-fi);
						rb(I,1,tmp){
							tt='9'+tt;
							base*=10;
						}
						bool ok=1;
						while(rest){
							tt=char('0'+min(rest,9ll-ok))+tt;
							rest-=min(rest,9ll-ok);
							base*=10;
							ok=0;
						}
						res=Min(res,tt);
					}
				}
			}
		}
		n=save;
	}	
	
	if(res[0]==':'){
		res="-1";
	}
	cout<<res<<endl;
}
signed main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
/*
1
123 2

1
26 4
896 897 898 899 900
*/