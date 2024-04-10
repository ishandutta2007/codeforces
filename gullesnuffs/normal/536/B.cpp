#include <bits/stdc++.h>
#define MOD 1000000007

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

char p[1000005];
int y[2000005];
int kmp[2000005];
int lenCommon[2000005];
bool filled[2000005];
long long poly[3][2000005];
long long A[3]={72837,18725,13},B[2]={82758273,82325},C[3]={7283753,1000000007,875827361};
long long pw[3][1000005];

int main(){
	int n,m;
	scanf("%d%d", &n, &m);
	scanf("%s",p);
	rep(i,0,m){
		scanf("%d", y+i);
		--y[i];
	}
	pw[0][0]=1;
	pw[1][0]=1;
	pw[2][0]=1;
	for(int j=0; j < 3; ++j)
		for(int i=1; i < 1000003; ++i){
			pw[j][i]=(pw[j][i-1]*A[j])%C[j];
		}
	int len=strlen(p);
	for(int j=0; j < 3; ++j){
	poly[j][0]=0;
	for(int i=0; i < len; ++i){
		poly[j][i+1]=(poly[j][i]*A[j]+p[i])%C[j];
	}
	}
	/*kmp[0]=-1;
	kmp[1]=0;
	for(int i=1; p[i]; ++i){
		kmp[i+1]=kmp[i];
		while(kmp[i+1] >= 0 && p[i] != p[kmp[i+1]])
			kmp[i+1]=kmp[kmp[i+1]];
		++kmp[i+1];
	}*/
	/*for(int i=len-1; i >= 1; --i){
		lenCommon[i]=kmp[i+1];
		while(lenCommon[i]){
			--i;
			lenCommon[i]=lenCommon[i+1]-1;
		}
	}*/
	int pos=0;
	int lastPos=-10000000;
	long long ans=1;
	for(int i=0; i < n; ++i){
		if(pos < m && i == y[pos]){
			if(i-lastPos < len){
				int pos2=i-lastPos;
				for(int j=0; j < 3; ++j){
					long long val1=poly[j][len]-poly[j][pos2]*pw[j][len-pos2];
					val1%=C[j];
					if(val1 < 0)val1+=C[j];	
					if(val1 != poly[j][len-pos2]){
						puts("0");
						return 0;
					}
				}
			}
			++pos;
			lastPos=i;
		}
		if(i-lastPos >= len){
			ans=(ans*26)%MOD;
		}
	}
	cout << ans << endl;
}