#include <bits/stdc++.h>

using namespace std;

#define rep(I, a, b) for(int I = (a); I < int(b); ++I)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

bool dp[2][11][11][11][11][11][32];
int a[25],b[25];
char ans[25][25];

struct Pre{
	int ind;
	int i[5];
	int bit;

	Pre(int _ind, int i1, int i2, int i3, int i4, int i5, int _bit){
		ind=_ind;
		i[0]=i1;
		i[1]=i2;
		i[2]=i3;
		i[3]=i4;
		i[4]=i5;
		bit=_bit;
	}
	Pre(){
	}

	bool operator<(const Pre &other) const{
		if(ind != other.ind)
			return ind < other.ind;
		if(bit != other.bit)
			return bit < other.bit;
		for(int j=0; j < 5; ++j){
			if(i[j] != other.i[j])
				return i[j] < other.i[j];
		}
		return 0;
	}
};
map<Pre, Pre> M;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,n)
		scanf("%d", a+i);
	rep(i,0,m)
		scanf("%d", b+i);
	rep(i,n,5)
		a[i]=0;
	bool read=0,write=1;
	dp[write][0][0][0][0][0][0]=1;
	rep(j,0,m){
		write^=1;
		read^=1;
		rep(i0,0,a[0]+1)
		rep(i1,0,a[1]+1)
		rep(i2,0,a[2]+1)
		rep(i3,0,a[3]+1)
		rep(i4,0,a[4]+1)
		rep(bit,0,32){
			dp[write][i0][i1][i2][i3][i4][bit]=0;
		}
		int i[5];
		rep(i0,0,a[0]+1)
		rep(i1,0,a[1]+1)
		rep(i2,0,a[2]+1)
		rep(i3,0,a[3]+1)
		rep(i4,0,a[4]+1)
		rep(bit,0,32){
			if(!dp[read][i0][i1][i2][i3][i4][bit])
				continue;
			i[0]=i0;
			i[1]=i1;
			i[2]=i2;
			i[3]=i3;
			i[4]=i4;
			bool ok=1;
			rep(p,0,5){
				if(i[p]+(m-j+2)/2<a[p])
					ok=0;
			}
			if(!ok)
				continue;
			rep(to,0,32){
				int num=0;
				rep(m,0,5){
					if(!(to&(1<<m)))
						continue;
					if(m==0 || (!(to&(1<<(m-1))))){
						++num;
					}
				}
				if(num != b[j])
					continue;
				int k[5];
				rep(l,0,5){
					k[l]=i[l];
					if(!(to&(1<<l)))
						continue;
					if(bit&(1<<l))
						continue;
					++k[l];
				}
				/*if(k[0] == 0 && k[1] == 1 && k[2] == 1 && k[3] == 1 && k[4] == 1 && to == 30 && j == 3){
					puts("1");
				}
				if(to == 16 && j == 2){
					puts("2");
				}*/
				dp[write][k[0]][k[1]][k[2]][k[3]][k[4]][to]=1;
				Pre now(j+1,k[0],k[1],k[2],k[3],k[4],to);
				Pre before(j,i[0],i[1],i[2],i[3],i[4],bit);
				M[now]=before;
			}
		}
	}
	rep(j,0,32){
		if(dp[write][a[0]][a[1]][a[2]][a[3]][a[4]][j]){
			Pre p(m,a[0],a[1],a[2],a[3],a[4],j);
			while(p.ind){
				rep(k,0,5){
					ans[k][p.ind-1]=(p.bit&(1<<k))?'*':'.';
				}
				p=M[p];
			}
			rep(k,0,n)
				printf("%s\n",ans[k]);
			return 0;
		}
	}
}