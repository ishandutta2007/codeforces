/*
{

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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=2e5+20;
int a[MAXN],pos[MAXN],n;
struct DA{
	int e1,e2,e3,e4;
}dp[MAXN];
DA EMPTY;
DA DATA (int e1,int e2,int e3,int e4){
		EMPTY.e1=e1;
		EMPTY.e2=e2;
		EMPTY.e3=e3;
		EMPTY.e4=e4;
		return EMPTY;
	}
bool check(bool ty,int A,int B){
	if(B==-1) return 0;
	if(ty){
		return A<B;
	}
	else{
		return A>B;
	}
}
int update(bool ty,int A,int B){
	if(B==-1) return A;
	if(ty){
		return max(A,B);		
	}
	else{
		return min(A,B);
	}
}
vector<int> ans1,ans2;
int x,y;
void print(bool flag1,bool flag2,int index,int ty){
	if(ty==1){
		ans1.PB(index);
		x=dp[index].e1;
		y=dp[index].e2;
	}
	else{
		ans2.PB(index);
		x=dp[index].e3;
		y=dp[index].e4;
	}
	if(index==1) return;
	if(ty==1){
		if(check(flag1,x,dp[index-1].e1)&&dp[index].e2==dp[index-1].e2){
			print(flag1,flag2,index-1,1);
		}
		else{
			print(flag1,flag2,index-1,2);
		}
	}
	else{
		if(check(flag2,y,dp[index-1].e2)&&dp[index].e3==dp[index-1].e1){
			print(flag1,flag2,index-1,1);
		}
		else{
			print(flag1,flag2,index-1,2);
		}
	}
} 
int res[MAXN];
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	fastio;
	R(n);
	rb(i,1,n){
		R(a[i]);
		pos[a[i]]=i;
	}
	if(n==1){
		cout<<"YES"<<endl<<1<<endl;
		return 0;
	}
	bool ok=1;
	rb(i,1,n){
		if(a[i]!=i){
			ok=0;
		}
	}
	if(ok){
		cout<<"YES"<<endl;
		cout<<1<<" ";
		rb(i,2,n){
			cout<<0<<" ";
		}
		cout<<endl;
		return 0;
	}
	ok=1;
	rl(i,n,1){
		if(a[i]!=(n-i)+1){
			ok=0;	
		}
	}
	if(ok){
		cout<<"YES"<<endl;
		cout<<1<<" ";
		rb(i,2,n){
			cout<<0<<" ";
		}
		cout<<endl;
		return 0;
	}
	rep(flag1,1)
		rep(flag2,2){
			if(!flag2) continue;
			rb(i,1,n){
				dp[i]=DATA(-1,-1,-1,-1);
				if(i==1){
					dp[i]=DATA(a[i],(flag2? INF:-INF),(flag1? INF:-INF),a[i]);
				}
				else{
					if(check(flag1,a[i],dp[i-1].e1)){
						dp[i].e1=a[i];
						dp[i].e2=update(flag2,dp[i-1].e2,dp[i].e2);
					}
					if(check(flag1,a[i],dp[i-1].e3)){
						dp[i].e1=a[i];
						dp[i].e2=update(flag2,dp[i-1].e4,dp[i].e2);
					}
					if(check(flag2,a[i],dp[i-1].e2)){
						dp[i].e4=a[i];
						dp[i].e3=update(flag1,dp[i-1].e1,dp[i].e3);
					}
					if(check(flag2,a[i],dp[i-1].e4)){
						dp[i].e4=a[i];
						dp[i].e3=update(flag1,dp[i-1].e3,dp[i].e3);
					}
				}
			}
			if(dp[n].e1!=-1&&dp[n].e2!=-1){
				print(flag1,flag2,n,1);
				reverse(ALL(ans1));
				reverse(ALL(ans2));
				cout<<"YES"<<endl;
				for(auto it:ans2){
					res[it]=1;
				}
				rb(i,1,n){
					cout<<res[i]<<" ";
				}
				cout<<endl;
				return 0;
			}
			if(dp[n].e3!=-1&&dp[n].e4!=-1){
				print(flag1,flag2,n,2);
				reverse(ALL(ans1));
				reverse(ALL(ans2));
				cout<<"YES"<<endl;
				for(auto it:ans2){
					res[it]=1;
				}
				rb(i,1,n){
					cout<<res[i]<<" ";
				}
				cout<<endl;
				return 0;
			}
		}
		cout<<"NO"<<endl;
	return 0;
}
/*

5
1 4 5 2 3

8
8 1 4 2 8 5 7 3 6

10
10 5 9 8 4 7 3 6 2 1


6
1 6 2 5 3 4


2
1 2


2
2 1

8
2 1 4 3 6 5 8 7

10
5 4 3 2 1 6 7 8 9 10

4
1 3 2 4

5 
1 2 3 4 5
1
1
*/