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
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;

int n,x,y;
int cnt[100000+20],al[100000+20],a[100000+20],res[100000+20];
bool cmp(int A,int B){
	if(al[a[A]]!=al[a[B]])
	return al[a[A]]>al[a[B]];
	return a[A]<a[B];
}
int find_(int l,int r){
	if(l==1) l++;
	int kk=0;
	rb(i,1,n+1){
		if(cnt[i]){
			kk++;
		}
	}
	if(kk==2){
		if(l&1){
			l++;
		}	
	}
	return min(r,l);
}
void solve(){
	get(n);
	get2(x,y);
	memset(cnt,0,sizeof(cnt));
	memset(al,0,sizeof(al));
	memset(res,0,sizeof(res));
	rb(i,1,n){
		get(a[i]);
		cnt[a[i]]++;
	}
	int pick=y-x;
	vector<int> pos;
	int ok=0;
	int f=find_(pick,n-x);
	ok=f-pick;
	pick=f;
	rb(i,1,n){
		if((al[a[i]]+1)*2>pick||pos.size()==pick){
			if(x){
				x--;
				res[i]=a[i];
			}
		}
		else{
			al[a[i]]++;
			pos.PB(i);
		}
	}
	if(pos.size()<pick){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	sort(ALL(pos),cmp);
	int zhi;
	rep(i,pos.size()){
		if(a[pos[i]]!=a[pos[0]]){
			zhi=i;
			break;
		}
	}
	rep(i,pos.size()){
		res[pos[zhi]]=a[pos[i]];
		zhi++;
		zhi%=pos.size();
	}
	int tmp;
	rb(i,1,n+1){
		if(!cnt[i]) tmp=i;
	}
	rb(i,1,n){
		if(!res[i])
			res[i]=tmp;
		else
		if(ok&&res[i]!=a[i]){
			ok--;
			res[i]=tmp;
		}
	}
	rb(i,1,n) cout<<res[i]<<" ";cout<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}