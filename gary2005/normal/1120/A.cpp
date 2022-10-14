/*
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
int b[500000+1],a[500000+1],cnt[500000+1],need[500000+1];
int kind=0;
int m,k,n,s;
bool check(int l,int r){vector<int> v;
	int need_=max(0,(r-l+1)-k);
	int len=min(r-l+1,k);
	int z=(l-1)/k;
	int st=1+z*k;
	int add=st+k-1;
	add=min(add,n*k);
	int ar=r;
	r=min(r,l+len-1);
	need_+=max(0,r-add);
	if(need_>m-(k*n)) return 0;
	rb(i,1,r-add){
		v.PB(i);
	}
	//cout<<v.size()<<endl;

	need_-=max(0,r-add);
	r=ar;//cout<<l<<" "<<r<<endl;
	memset(cnt,0,sizeof(cnt));
	if(need_)
	rb(i,l,r){
		cnt[a[i]]++;
		if(cnt[a[i]]-1>=need[a[i]]){
			cnt[a[i]]--;
			v.PB(i);
			need_--;
			if(need_==0) {
					
				break;
			}
		}
	}cout<<v.size()<<endl;
				for(auto it:v){
					cout<<it<<" ";
				}
	return 1;
}
int main(){
	fastio;
	cin>>m>>k>>n>>s;
	rb(i,1,m)
		cin>>a[i];
	rb(i,1,s){
		cin>>b[i];
		need[b[i]]++;
		if(need[b[i]]==1){
			kind++;
		}
	}
	int r=-1;
	int ok=0;
	vector<mp> seg;
	rb(i,1,m){
		cnt[a[i]]++;
		if(cnt[a[i]]==need[a[i]]){
			ok++;
		} 
		if(ok==kind){
//			cout<<i<<" "<<a[i]<<endl;
			r=i;
			break;
		}
	}
	if(r==-1){
		cout<<-1<<endl;exit(0);
	}
	seg.PB(II(1,r));
//	cout<<1<<" "<<r<<endl;
//		cout<<need[2]<<endl;
	rb(i,2,m){
		cnt[a[i-1]]--;
//		cout<<a[i-1]<<endl;
		if(cnt[a[i-1]]+1==need[a[i-1]]){
			ok--;
//			cout<<"1"<<endl;
			rb(j,r+1,m){
				cnt[a[j]]++;
				if(cnt[a[j]]==need[a[j]]) {
				r=j;
				ok++;
				break;
				}
			}
			if(ok!=kind){
				r=-1;
			}
		}
		if(r==-1) break;
		seg.PB(II(i,r));
//		cout<<i<<" "<<r<<endl;
	}
	for(auto it:seg){
		 
		if(check(it.FIR,it.SEC)){
			return 0;	
		}
	}
	cout<<-1<<endl;
	return 0;
}