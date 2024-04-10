#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string ss,t;
int go[100005],go2[100005],q;
struct RMQ{
	#define s (1<<18)
	int seg[s];
	void update(int k,int a){
		k+=s/2-1; seg[k]+=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=(seg[k*2+1]+seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return (vl+vr);
		}
	}
	int query(int a,int b){
		return query(a,b,0,0,s/2-1);
	}
}S,T;
int main(){
	cin>>ss>>t;
	rep(i,ss.size()){
		if(ss[i] != 'A'){
			go[i] = 0;
			S.update(i,1);
		}
		else{
			go[i] = 1;
			if(i) go[i] += go[i-1];
		}
	}
	rep(i,t.size()){
		if(t[i] != 'A'){
			go2[i] = 0;
			T.update(i,1);
		}
		else{
			go2[i] = 1;
			if(i) go2[i] += go2[i-1];
		}
	}
	cin>>q;
	string ans = "";
	rep(i,q){
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
		int L = min(go[b-1],b-a+1);
		int R = min(go2[d-1],d-c+1);
		int x = S.query(a-1,b-1);
		int y = T.query(c-1,d-1);
		if(L < R){
			ans.pb('0');
		}
		else{
			if(L == R && x == 0 && y){
				ans.pb('0'); continue;
			}
			if((L-R)%3 != 0){
				x+=2;
			}
			if(x<=y && x%2==y%2){
				ans.pb('1');
			}
			else{
				ans.pb('0');
			}
		}
	}
	cout<<ans<<endl;
}