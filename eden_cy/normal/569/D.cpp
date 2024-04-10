#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 4005

typedef long long ll;
const int Mod=(int)1e9+7;

ll bell[M];
ll C[M];
int main() {
	bell[0]=bell[1]=1;
	C[0]=1;
	FOR(i,2,M-1) {
		C[i-1]=bell[i-1];
		DOR(j,i-2,0) C[j]=(C[j]+C[j+1])%Mod;
		bell[i]=C[0];
	}
	int n;
	scanf("%d",&n);
	printf("%lld\n",(bell[n+1]-bell[n]+Mod)%Mod);
	return 0;
}