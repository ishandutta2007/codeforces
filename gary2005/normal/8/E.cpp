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
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
#define int LL
int n;
LL k;
bool vis[26][2][2][2];//i<,<=>,reverse , 
LL f[26][2][2][2];
LL stn(string s){
	if(s.length()==0) return 1;
	LL f[55][2];
	if(s[0]=='1'){
		f[0][0]=1;
		f[0][1]=1; 
	}
	else{
		f[0][0]=0;
		f[0][1]=1;//eq
	}
	rb(i,1,s.length()-1){
		if(s[i]=='1'){
			f[i][0]=f[i-1][0]*2+f[i-1][1];
			f[i][1]=f[i-1][1];
		}
		else{
			f[i][0]=f[i-1][0]*2;
			f[i][1]=f[i-1][1];
		}
	} 
	return f[s.length()-1][0]+f[s.length()-1][1];
}
LL dfs(string s,int alr,bool flag1,bool flag2,bool flagr){
	if(vis[alr][flag1][flag2][flagr]){
		return f[alr][flag1][flag2][flagr];
	}
	if(s.length()<=1){
//		cout<<s<<" "<<alr<<" "<<flag1<<" "<<flag2<<endl;
		if(s.length()==0){
			if(flag1+flag2!=0)return 1;
			return 0;
		} 
		if(flagr==1){
			//must put 0
			flag1|=(s[0]>'0');
			if(flag1+flag2==0){
				//    
				return 0;
			}
			return 1;
		}
		int rest=0;//put 0
		if((flag1|(s[0]>'0'))+flag2!=0){
			rest++;	
		}	//put 1 
		if(s[0]=='0') rest+=flag1;
		else
		if((flag1)+flag2!=0){
			rest++;	
		}
//		cout<<flag1<<" "<<flag2<<" "<<flagr<<" "<<rest<<endl;
		return rest;
	}
	vis[alr][flag1][flag2][flagr]=1;
	LL res=0;
	char fi,la;
	fi=s[0];
	la=s[s.length()-1];
	string ss=s.substr(1,s.length()-2);
	if(flagr){
		/*
		0 1 -> con
		1 0 -> con
		0 0 ->  
		*/
		LL tmp=stn(ss);//0 0
//		cout<<ss<<" "<<tmp<<endl;
		if((flag1|(fi=='1'))){
			tmp=(1ll<<ss.length());
//			if(tmp==0) tmp=1;
		}
		else{
			if((flag2|(la>'0'))){
				
			}
			else{
				tmp--;
			}	
		}
		if(tmp>0){
			res+=tmp;
		}//0 1		
//		cout<<tmp<<endl;
		res+=dfs(ss,alr+1,flag1|(fi>'0'),(la=='1')&flag2,flagr);
		if(flag1||fi=='1'){//1 0
			res+=dfs(ss,alr+1,flag1,(la=='1')|flag2,flagr);
		}	
	}
	else{
		/*
		0 0 -> con
		1 1 -> con
		0 1 -> 
		*/
		LL tmp=stn(ss);// 0 1
		if((flag1|(fi=='1'))){
			tmp=(1ll<<ss.length());
		}
		else{
			if((flag2&(la=='1'))){
				
			}
			else{
				tmp--;
			}		
		}
		if(tmp>0){
			res+=tmp;
		}
		//0 0
		res+=dfs(ss,alr+1,(flag1|(fi=='1')),flag2|(la=='1'),flagr);
		/*1 1*/if(flag1||fi=='1') res+=dfs(ss,alr+1,flag1,flag2&(la=='1'),flagr);
	}
	return f[alr][flag1][flag2][flagr]=res;
}
LL get(LL num){
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
	string s;
	rep(i,n){
		s+=char((num&(1ll<<i))? '1':'0'); 
	}
	reverse(ALL(s));
//	cout<<s<<endl;
	string s1=s.substr(1,s.length()-2);//0 1
//	cout<<dfs(s1,0,s[0]=='1' ,s[s.length()-1]=='1',1)<<"+"<<dfs(s1,0,s[0]=='1',1,0)<<endl;//0 0
	return dfs(s1,0,s[0]=='1',s[s.length()-1]=='1',1)+dfs(s1,0,s[0]=='1',1,0);//0 0
//	return 1;
}
signed main(){
	fastio;
	R2(n,k);
	k++;
//	if(n==2){
//		cout<<-1<<endl;return 0;
//	}
//	cout<<stn("10")<<" "<<stn("01")<<endl;
//	cout<<get(9)<<endl; 
//	return 0;
	LL l,r;
	if(get((1ll<<(n-1))-1)<k){
		cout<<-1<<endl;
		return 0;
	}
	l=1,r=(1ll<<(n-1))-1;
//	cout<<r<<endl;
	while(l<r){
		LL mid=(l+r)>>1;
		if(get(mid)<k) {
			l=mid+1;
		}
		else r=mid;
	}
//	cout<<l<<" "<<get(6)<<endl;
	rl(i,n-1,0){
		if((l)&(1ll<<i)){
			cout<<'1';
		}
		else 
		cout<<'0';
	}
	return 0;
}
/*







3 2

6 2

*/