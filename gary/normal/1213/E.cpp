//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string res;string s,t;int n;
void proces(){
	if(t[1]==t[0]){
		swap(s,t);
	}
	if(s[0]==s[1]){
		if(t[0]==t[1]){
			if(t[0]==s[0]){
				char c;
				rep(i,3){
					c='a'+i;
					if(c!=s[0]) break;
				}
				char empt;
				rep(i,3){
					empt='a'+i;
					if(empt!=c&&empt!=s[0]) break;
				}
				rep(i,n) res[i]=empt;
				rep(i,n+n){
					if(i&1){
						res[i+n]=s[0];
					}
					else{
						res[i+n]=c;
					}
				}
			}
			else{
				char c;
				c=t[0];
				char empt;
				rep(i,3){
					empt='a'+i;
					if(empt!=c&&empt!=s[0]) break;
				}
				rep(i,n) res[i]=empt;
				rep(i,n+n){
					if(i&1){
						res[i+n]=s[0];
					}
					else{
						res[i+n]=c;
					}
				}
			}
		}
		else{
			if(t[0]==s[0]){
				rep(i,n) res[i]=t[1];
				char c;
				rep(i,3){
					c='a'+i;
					if(c!=s[0]&&c!=t[1]) break;
				}
				rep(i,n+n) res[i+n]=((i&1)? s[0]:c);
			}
			else{
				if(t[1]==s[0]){
					rep(i,n) res[i+2*n]=t[0];
					char c;
					rep(i,3){
						c='a'+i;
						if(c!=s[0]&&c!=t[0]) break;
					}
					rep(i,n) res[i+n*2]=t[0];
					rep(i,n+n){
						if(i&1){
							res[i]=s[0];
						}
						else{
							res[i]=c;
						}
					}
				}
				else{
					rep(i,n) res[i]=t[1];
					rep(i,n+n){
						if(i&1){
							res[i+n]=s[0];
						}
						else{
							res[i+n]=t[0];
						}
					}
				}
			}
		}
		return;
	}
	if(s[0]==t[0]){
			char c1,c2;
			rep(i,3) {
				c1='a'+i;
				if(c1!=s[0]) break;
			}
			rep(i,3){
				c2='a'+i;
				if(c2!=c1&&c2!=s[0]) break;
			}
			rep(i,n) res[i]=c1;
			rep(i,n) res[i+n]=c2;
			rep(i,n) res[i+2*n]=s[0];
	}
	else{
		if(s[1]==t[0]) swap(s,t);
		if(s[1]==t[0]){
			char c;
			rep(i,n) res[i]=s[0];
			rep(i,n) res[i+2*n]=s[1];
			rep(i,3){
				c='a'+i;
				if(c!=s[0]&&c!=s[1]) break;
			}
			rep(i,n) res[i+n]=c;
		}
		else{
		rep(i,n) res[i]=s[1];
		rep(i,n) res[i+n]=s[0];
		rep(i,n) res[i+2*n]=t[0];	
		}
		
	}
}
int main(){
	//
	cin>>n;
	rep(i,n*3) res+='$';
	
	cin>>s>>t;
	int OK=0;
	if(s[1]==t[1]){
		swap(s[0],s[1]),swap(t[0],t[1]);
		OK=1;
	}
	puts("YES");
	proces();
	if(OK){
		rl(i,n+n+n-1,0) cout<<res[i];
	}
	else{
		cout<<res;
	}
	cout<<endl;
	return 0;
}