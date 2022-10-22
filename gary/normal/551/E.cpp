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
int n,q,block_num;
LL add[1000+10],a[500000+10];
multiset<mp> block[1000+10];//700
inline int calc_block(int x){
	return x/700+bool(x%700);
}
int main(){
	fastio;
	cin>>n>>q;
	block_num=(n+699)/700;
	rb(i,1,n){
		int ai;
		cin>>ai;
		a[i]=ai;
		block[calc_block(i)].insert(II(ai,i));	
	}
	rb(Q,1,q){
		int ty;
		cin>>ty;
		if(ty==1){
			int l,r,x;
			cin>>l>>r>>x;
			while(l%700!=1&&l<=r){
				block[calc_block(l)].erase(II(a[l],l));
				a[l]+=x;
				block[calc_block(l)].insert(II(a[l],l));
				l++;
			}
			while(r%700!=0&&l<=r){
				block[calc_block(r)].erase(II(a[r],r));
				a[r]+=x;
				block[calc_block(r)].insert(II(a[r],r));
				r--;
			}
			if(l<=r){
			int tmp1=calc_block(l),tmp2=calc_block(r);
			rb(i,tmp1,tmp2){
				add[i]+=x;
			}	
			}
			
		}
		else{
			int y,fir=-1,sec=0;
			cin>>y;
			rb(i,1,block_num){
				mp s;
				if((LL)(y)-add[i]<0) continue;
				if(block[i].lower_bound(II(y-add[i],-1))!=block[i].end()){
					s=*block[i].lower_bound(II(y-add[i],-1));
					if(s.FIR==y-add[i]){
						fir=s.SEC;
						break;
					}
				}
			}
			if(fir==-1){
				cout<<fir<<endl;
				continue;
			}
			rl(i,block_num,1){
				mp s;
				if((LL)(y)-add[i]<0) continue;
				if(block[i].upper_bound(II(y-add[i],INF))!=block[i].begin()){
					multiset<mp> :: IT ite=block[i].upper_bound(II(y-add[i],INF));
					ite--;
					s=*ite;
					if(s.FIR==y-add[i]){
						sec=s.SEC;
						break;
					}
				}
			}
			cout<<sec-fir<<endl;
		}
	}	
	return 0;
}