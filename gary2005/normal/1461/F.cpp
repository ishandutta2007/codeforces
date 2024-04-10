/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
int n,a[100000+20];
bool in(string & s,char c){
	rep(i,s.length()) if(s[i]==c) return true;
	return false;
}
string ans;
LL dp[100000+20];
int p[100000+20];
deque<int> pos;
string solve2(int l,int r){
	pos.clear();
	string ret;
	LL tmp=1;
	rb(i,l,r){
		tmp*=a[i];	
		if(tmp>1ll*(r-l+1)*(r-l+1)){
			rb(j,l,r-1){
				ret+=char('0'+a[j]);
				ret+='*';
			}
			ret+=char('0'+a[r]);
			return ret;
		}
	}
	rb(i,l,r){
		dp[i]=dp[i-1]+a[i];
		p[i]=i-1;
		if(a[i]!=1){
			pos.PB(i);
			if(pos.size()>20) pos.pop_front();
		}
		LL tmp2=1;
		rl(j,pos.size()-1,0){
			tmp2=tmp2*a[pos[j]];
			if(dp[pos[j]-1]+tmp2>dp[i]){
				dp[i]=dp[pos[j]-1]+tmp2;
				p[i]=pos[j]-1;
			}
		}
	}
	if(dp[r]<tmp){
		rb(j,l,r-1){
			ret+=char('0'+a[j]);
			ret+='*';
		}
		ret+=char('0'+a[r]);
		return ret;
	}
	int now=r;
	while(now!=l-1){
		rl(i,now,p[now]+1){
			ret+=char('0'+a[i]);
			if(i!=l){
				if(i==p[now]+1)
					ret+='+';
				else 
					ret+='*';
			}
		}
		now=p[now];
	}
	reverse(ALL(ret));
	return ret;
}
string solve(int l,int r){
	string ret;
	while(l<r&&a[l]==1){
		ret+=char('0'+a[l]);
		ret+='+';
		++l;
	}
	if(l==r&&a[l]==1){
		ret+='1';
		return ret;
	}
	int z=0;
	while(l<r&&a[r]==1){
		r--;
		z++;
	}
//	cout<<l<<' '<<r<<endl;
	ret+=solve2(l,r);
	rb(i,1,z){
		ret+="+1";
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	string s;
	cin>>s;
	if(s.length()==1){
		rb(i,1,n){
			printf("%d",a[i]);
			if(i!=n){
				cout<<s[0];
			}
		}
		return 0;
	}
	if(!in(s,'*')){
		rb(i,1,n){
			printf("%d",a[i]);
			if(i!=n){
				cout<<'+';
			}
		}
		return 0;
	}
	if(!in(s,'+')){
		bool flag=0;
		rb(i,1,n){
			printf("%d",a[i]);
			if(i!=n){
				if(a[i+1]==0&&!flag){
					cout<<'-';
					flag=1;
				}
				else cout<<'*';
			}
		}
		return 0;
	}
	int l=-1;
	rb(i,1,n){
		if(a[i]==0){
			if(l!=-1){
				ans+=solve(l,i-1);
				ans+='+';
			}
			l=-1;
			ans+="0";
			if(i!=n) ans+="+";
		}
		else{
			if(l==-1) l=i;
		}
	}
	if(l!=-1) ans+=solve(l,n); 
	cout<<ans<<endl; 
	return 0;
}
/*
34 
0 2 4 8 4 9 9 8 9 8 8 4 7 4 2 3 5 8 7 5 2 5 5 9 4 2 8 8 9 5 1 4 3 0
5
0 4 8 1 0
+* 
*/