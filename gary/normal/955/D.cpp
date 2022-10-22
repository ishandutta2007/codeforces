/*
D:
AuThOr GaRyMr
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int z[600000+10+600000+10],form[600000+10][2],n,m,k;
string s,t;
void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	memset(z,0,sizeof(z));
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
//	cout<<z[2]<<endl;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
//		cout<<i<<" "<<z[i]<<" "<<S[i]<<endl; 
	}
	rb(i,1,n)
		z[i]=z[i+t.length()+1];
}
set<int> em;
set<int> :: IT ite;
int main(){
	fastio;
	cin>>n>>m>>k>>s>>t;
	z_function(string (t+'&'+s));
	rb(i,1,n){
		if(z[i]==m){
			rb(j,1,n){
				if(j+k+k-1>=i+z[i]-1){
					cout<<"Yes\n"<<j<<" "<<j+k<<'\n';
					return 0;
				}
			}
		}
	}
	rb(i,1,n)
		em.insert(i);
	rb(i,1,n){
		if(!z[i]) continue;
		if(i+z[i]-1<k) continue;
		int l,r=z[i];
		if(i<k){
			l=k-i+1;
		}
		else{
			l=1;
		}
		ite=em.lower_bound(l);
		while(ite!=em.end()&&*ite<=r){
			form[*ite][0]=i;
			em.erase(ite++);
		}
	}
	em.empty();
	reverse(ALL(s)),reverse(ALL(t));
	z_function(string (t+'&'+s));
	rb(i,1,n)
		em.insert(i);
	rb(i,1,n){
		if(!z[i]) continue;
		if(i+z[i]-1<k) continue;
		int l,r=z[i];
		if(i<k){
			l=k-i+1;
		}
		else{
			l=1;
		}
		ite=em.lower_bound(l);
		while(ite!=em.end()&&*ite<=r){
			form[*ite][1]=n-i+1;
			em.erase(ite++);
		}
	}
	rb(i,1,m-1){
		if(form[i][0]&&form[m-i][1]&&i<=k&&m-i<=k){
			int L,R;
			R=form[m-i][1]-(m-i)+1;
			L=form[i][0]+i-1; 
			L-=k;
			L++;
			if(L+k-1<R){
				cout<<"Yes\n";
				cout<<L<<" "<<R<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;	
}