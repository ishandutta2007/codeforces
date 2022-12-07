#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

template<typename T>inline void ckmax(T& x,T y){x=(y>x?y:x);}
template<typename T>inline void ckmin(T& x,T y){x=(y<x?y:x);}

const int MAXN=2e5,LOG=18;
int n;
uint s[MAXN+5];
uint mask_to_val[MAXN+5];
struct LinerBase{
	int size;
	uint base[MAXN+5],mask[MAXN+5],val[MAXN+5];
	void insert(const uint& v){
		uint t=v;
		uint ma=0;
		for(int i=LOG;i>=0;--i) if((t>>i)&1) {
			if(!base[i]){
				base[i]=t;
				++size;
				ma|=(1<<(size-1));
				mask[i]=ma;
				val[size]=v;
				return;
			}
			else{
				t^=base[i];
				ma^=mask[i];
			}
		}
	}
	uint query_mask(const uint& v){
		uint t=v;
		uint ma=0;
		for(int i=LOG;i>=0;--i) if((t>>i)&1) {
			assert(base[i]);
			t^=base[i];
			ma^=mask[i];
		}
		return ma;
	}
}B;
vector<uint> get_gray(uint x){
	if(x==0){
		vector<uint> res(1,0);
		return res;
	}
	vector<uint> res=get_gray(x-1);
	uint len=(1u<<(x-1));
	for(uint i=0;i<len;++i){
		res.push_back(res[len-1-i] | (1u<<(x-1)));
	}
	return res;
}
int main() {
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int j=0;
	int x=-1;
	for(int i=0;i<=LOG;++i){
		while(j+1<=n && s[j+1]<(1u << i)){
			++j;
			B.insert(s[j]);
		}
		if(B.size==i) x=i;
	}
	assert(x!=-1);
	for(uint i=0;i<(1u<<x);++i){
		mask_to_val[B.query_mask(i)]=i;
	}
//	cerr<<x<<endl;
//	for(uint i=0;i<(1u<<x);++i)
//		cerr<<mask_to_val[i]<<" ";
//	cerr<<endl;
	vector<uint> v=get_gray(x);
	cout<<x<<endl;
	for(uint i=0;i<(1u<<x);++i){
		cout<<mask_to_val[v[i]]<<" ";
	}
	cout<<endl;
	return 0;
}