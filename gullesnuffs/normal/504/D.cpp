#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char s[2005];
bitset<2000> ten[605][10];
bitset<2000> A[2005];
bitset<2000> B[2005];
bitset<2000> comp[2005];
bitset<2000> bcomp[2005];

bitset<2000> addTo(bitset<2000>& a, bitset<2000>& b){
	int carry=0;
	rep(i,0,2000){
		if(b.test(i) || carry){
			if(b.test(i) && carry){
				carry=1;
			}
			else{
			if(a.test(i)){
				a.set(i,0);
				carry=1;
			}
			else{
				a.set(i,1);
				carry=0;
			}
		}
		}
	}

}
bitset<2000> addTo2(bitset<2000>& a, bitset<2000> b){
	int carry=0;
	rep(i,0,2000){
		if(b.test(i) || carry){
			if(b.test(i) && carry){
				carry=1;
			}
			else{
			if(a.test(i)){
				a.set(i,0);
				carry=1;
			}
			else{
				a.set(i,1);
				carry=0;
			}
			}
		}
	}
}
bitset<2000> times(bitset<2000> a, int b){
	bitset<2000> ret;
	ret.reset();
	for(int i=0; (1<<i) <= b; ++i){
		if(b&(1<<i))
			addTo2(ret,a<<i);
			//ret=add(ret,(a<<i));
	}
	return ret;
}


int main(){
	int m;
	scanf("%d", &m);
	/*for(int i=0; i < 602; ++i){
		rep(j,0,10)
			ten[i][j].reset();
		if(i)
			ten[i][1]=times(ten[i-1][1], 10);
		else
			ten[0][1].set(0, true);
		for(int j=2; j < 10; ++j)
			ten[i][j]=times(ten[i][1], j);
	}*/	
	rep(i,0,m){
		scanf("%s", s);
		int l=strlen(s);
		A[i].reset();
		comp[i].reset();
		rep(j,0,l/2){
			swap(s[j],s[l-j-1]);
		}
		rep(j,0,l)
			s[j]-='0';
		rep(k,0,2000){
		A[i].set(k,s[0]%2);
		rep(j,0,l){
			s[j]=s[j]/2+5*(s[j+1]&1);
			//A[i]^=ten[l-j-1][s[j]-'0'];		
			//A[i]=add(A[i],ten[l-j-1][s[j]-'0']);
			//addTo(A[i],ten[l-j-1][s[j]-'0']);
		}
		if(s[l-1]==0)
			--l;
		}
		comp[i].set(i);
		rep(j,0,2000){
			if(A[i].test(j)){
				if(B[j].any()){
					comp[i]^=bcomp[j];
					A[i]^=B[j];
				}
				else{
					B[j]=A[i];
					bcomp[j]=comp[i];
					break;
				}
				/*while(pos < i && f[pos] < j)
					++pos;
				if(pos == i){
					f[i]=j;
					break;
				}
				else if(A[pos].test(j)){
					A[i]^=A[pos];
					comp[i]^=comp[pos];
					++pos;
				}
				else{
					swap(A[pos],A[i]);
					swap(comp[pos],comp[i]);
					f[pos]=j;
					++pos;
				}*/
			}
		}
		if(A[i].any()){
			puts("0");
		}
		else{
			vector<int> print;
			rep(j,0,i){
				if(comp[i].test(j))
					print.push_back(j);
			}
			printf("%d ", print.size());
			rep(j,0,print.size())
				printf("%d ", print[j]);
			printf("\n");
		}
	}
}