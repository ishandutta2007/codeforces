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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void check(string & s1,string s2){
	if(s2.length()==s1.length()){
		if(s2<s1) s1=s2;
		return ;
	}
	if(s2.length()<s1.length()){
		s1=s2;
	}
}
int x[8],y[8],z[8];
string dp[256][3];
int getval(string s){
	int val=0;
	rep(i,s.length()){
		val+=val;
		val+=s[i]-'0';
	}
	return val;
}
map<char,int> ma;
int main(){
	ma['!']=0;
	ma['|']=2;
	ma['&']=1;
	rep(i,256){
		dp[i][0]="";
		rb(j,1,10000) dp[i][0]+='$';
		rep(j,3) dp[i][j]=dp[i][0];
	}
	rep(i,8) x[i]=(i/4),y[i]=(i/2)%2,z[i]=i%2;
	string s="";
	rep(i,8){
		s+=char(x[i]+'0');
	}
	dp[getval(s)][0]="x";
	s="";
	rep(i,8){
		s+=char(y[i]+'0');
	}
//	cout<<s<<endl;
	dp[getval(s)][0]="y";
	s="";
	rep(i,8){
		s+=char(z[i]+'0');
	}
	dp[getval(s)][0]="z";
	rb(i,1,3*256){
		bool ok=0;
		rep(j,256){
			rep(k,256){
				rep(t1,3){
					rep(t2,3){
						if(dp[j][t1][0]=='$'||dp[k][t2][0]=='$') continue;
						rep(t3,3){
							int ni;
							string tmp;
							if(t3==0){
								ni=255^j;
							}
							if(t3==1){
								ni=j&k;
							}
							if(t3==2){
								ni=j|k;
							}
							if(dp[j][t1].length()+dp[k][t2].length()>=dp[ni][t3].length()){
								continue;
							}
							if(t3==0){
								if(t1==0)
								tmp="!"+dp[j][t1];
								else 
								tmp="!("+dp[j][t1]+")";
							}
							if(t3==1){
								if(t1>t3){
									tmp="("+dp[j][t1]+")";
								}
								else tmp=dp[j][t1];
								tmp+='&';
								if(t2>t3){
									tmp+="("+dp[k][t2]+")";
								}
								else tmp+=dp[k][t2];
							}
							if(t3==2){
//								cout<<"!"<<endl;
//								if(j==getval("00110011")&&k==getval("01010101")){
//									cout<<t1<<' '<<t2<<endl;
//									cout<<"!"<<endl;
//								}
								if(t1>t3){
									tmp="("+dp[j][t1]+")";
								}
								else tmp=dp[j][t1];
								tmp+='|';
								if(t2>t3){
									tmp+="("+dp[k][t2]+")";
								}
								else tmp+=dp[k][t2];
							}
							string old=dp[ni][t3];
							check(dp[ni][t3],tmp);
							if(old!=dp[ni][t3]) ok=1;
						}
					}
				}
			}
		}
		if(!ok) break;
	}
	int t;
	cin>>t;
	rb(Q,1,t){
		string s;
		cin>>s;
		string ss=dp[getval(s)][0];
		rep(j,3) check(ss,dp[getval(s)][j]);
		cout<<ss<<endl;
	}
	return 0;
}