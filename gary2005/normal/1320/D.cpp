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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int las[200000+20]/*0*/,nex[200000+20]/*0*/,block[200000+20],siz[200000+20],n,t[200000+20];
int x=1e9+3,y=1e9+7;
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL x=quick(A,B>>1);
	x*=x;
	x%=y;
	if(B&1){
		x*=A;
		x%=y;
	}
	return x;
}
LL hash_val[200000+20];
LL getval(int l,int r){
	return (hash_val[r]-hash_val[l-1]*quick(x,r-l+1)%y+y)%y; 
} 
int main(){
	fastio;
	cin>>n;
	rb(i,1,n){
		char c;
		cin>>c;
		t[i]=c-'0';
	}
	rb(i,1,n+1){
		las[i]=las[i-1];
		if(i<=n&&t[i]==0){
			las[i]=i;
		}
	}
	nex[n+1]=n+1;
	rl(i,n,1){
		nex[i]=nex[i+1];
		if(t[i]==0){
			nex[i]=i;
		}
	}
	int cnt=1;
	rb(i,1,n){
		block[i]=cnt;
		siz[cnt]^=1;
		if(t[i]==0){
			cnt++;
		}
	}
	rb(i,1,n){
		siz[i]+=13;
	}
	rb(i,1,n){
		hash_val[i]=hash_val[i-1]*x%y+siz[i];
		hash_val[i]%=y;
	}
	int q;
	cin>>q;
	while(q--){
		int l1,l2,r1,r2;
		cin>>l1>>l2>>r1;
		r2=l2+r1-1;
		r1=l1+r1-1;
		int s1,s2,s3,s4;
		s1=block[l1];
		s2=block[r1];
		s3=block[l2];
		s4=block[r2];
		if(t[r1]==0){
			s2++;
		}
		if(t[r2]==0){
			s4++;
		}
		s1++;
		s2--;
		s3++;
		s4--;
		bool ok=1;
		if((min(r1,nex[l1])-l1)%2!=(min(r2,nex[l2])-l2)%2||(r1-max(l1,las[r1]))%2!=(r2-max(las[r2],l2))%2){
			ok=0;
		}
		else{
			if(s4-s3!=s2-s1){
				ok=0;
			}
			else{
				if(s2<s1){
					ok=1;
				}
				else{
					if(getval(s1,s2)!=getval(s3,s4)){
						ok=0;
					}
				}
			}
		}
		if(ok){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}